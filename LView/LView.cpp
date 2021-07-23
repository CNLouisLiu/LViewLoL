#define BOOST_DEBUG_PYTHON 
#define USE_IMPORT_EXPORT
#define USE_WINDOWS_DLL_SEMANTICS
#define STB_IMAGE_IMPLEMENTATION

#include "PyStructs.h"

#include <iostream>
#include "windows.h"
#include "Utils.h"
#include "Structs.h"
#include "LeagueMemoryReader.h"
#include "Offsets.h"
#include "AntiCrack.h"
#include "MapObject.h"
#include "GameData.h"

#include <chrono>
#include "Overlay.h"
#include <map>
#include <list>
#include <conio.h>

using namespace std::chrono;

/* bool Authenticate(); */
void MainLoop(Overlay& overlay, LeagueMemoryReader& reader);

int main()
{
	printf(
		"	:::    :::     ::: ::::::::::: :::::::::: :::       ::: \n"
		"	:+:    :+:     :+:     :+:     :+:        :+:       :+: \n"
		"	+:+    +:+     +:+     +:+     +:+        +:+       +:+ \n"
		"	+#+    +#+     +:+     +#+     +#++:++#   +#+  +:+  +#+ \n"
		"	+#+     +#+   +#+      +#+     +#+        +#+ +#+#+ +#+ \n"
		"	#+#      #+#+#+#       #+#     #+#         #+#+# #+#+#  \n"
		"	########## ###     ########### ##########   ###   ###   \n\n"
	);

	Overlay overlay = Overlay();
	LeagueMemoryReader reader = LeagueMemoryReader();

	try {
		printf("[+] Initializing PyModule\n");
		PyImport_AppendInittab("lview", &PyInit_lview);
		Py_Initialize();

		printf("[+] Initialising imgui and directx UI\n");
		overlay.Init();

		printf("[+] Loading static map data\n\n");
		MapObject::Get(MapType::SUMMONERS_RIFT)->Load("data/height_map_sru.bin");
		MapObject::Get(MapType::HOWLING_ABYSS)->Load("data/height_map_ha.bin");

		printf("[+] Loading unit data\n");
		std::string dataPath("data");
		GameData::Load(dataPath);

		MainLoop(overlay, reader);

		Py_Finalize();
	}
	catch (std::runtime_error exception) {
		std::cout << exception.what() << std::endl;
	}

	printf("Press any key to exit...");
	getch();
}

void MainLoop(Overlay& overlay, LeagueMemoryReader& reader) {

	MemSnapshot memSnapshot;
	bool rehook = true;
	bool firstIter = true;

	printf("[i] Waiting for league process...\n");
	while (true) {

		bool isLeagueWindowActive = reader.IsLeagueWindowActive();
		if (overlay.IsVisible()) {
			// One some systems the ingame cursor is replaced with the default Windows cursor
			// With the WS_EX_TRANSPARENT window flag enabled the cursor is as expected but the user cannot control the overlay
			if (Input::WasKeyPressed(HKey::F8)) {
				overlay.ToggleTransparent();
			}
			if (!isLeagueWindowActive) {
				overlay.Hide();
			}
		}
		else if (isLeagueWindowActive) {
			overlay.Show();
		}

		try {
			overlay.StartFrame();

			// Try to find the league process and get its information necessary for reading
			if (rehook) {
				reader.HookToProcess();
				rehook = false;
				firstIter = true;
				memSnapshot = MemSnapshot();
				printf("[i] Found league process. The UI will appear when the game stars.\n");
			}
			else {

				if (!reader.IsHookedToProcess()) {
					rehook = true;
					printf("[i] League process is dead.\n");
					printf("[i] Waiting for league process...\n");
				}
				reader.MakeSnapshot(memSnapshot);

				// If the game started
				if (memSnapshot.gameTime > 2.f) {

					// Tell the UI that a new game has started
					if (firstIter) {
						overlay.GameStart(memSnapshot);
						firstIter = false;
					}
					overlay.Update(memSnapshot);
				}
			}
		}
		catch (WinApiException exception) {
			// This should trigger only when we don't find the league process.
			rehook = true;
		}
		catch (std::runtime_error exception) {
			printf("[!] Unexpected error occured: \n [!] %s \n", exception.what());
			break;
		}
		overlay.RenderFrame();
	}
}

/*

#include <aws/core/Aws.h>
#include <aws/lambda/LambdaClient.h>
#include <aws/lambda/model/InvokeRequest.h>

#include <aws/core/auth/AWSCredentials.h>
#include <aws/core/client/ClientConfiguration.h>

/// Authentication using AWS. Calls a lambda from AWS that will do the authentication.
bool Authenticate() {


	Aws::SDKOptions options;
	Aws::InitAPI(options);

	ConfigSet* cfg = ConfigSet::Get();
	cfg->SetPrefixKey("auth");
	std::string name = cfg->GetStr("user", "");
	std::string region = cfg->GetStr("region", "");
	std::string accessKey = cfg->GetStr("access_key", "");
	std::string secretKey = cfg->GetStr("secret_key", "");
	cfg->SetPrefixKey("");

	if (region.empty() || name.empty() || accessKey.empty() || secretKey.empty()) {
		printf("[!] auth:: config fields are missing");
		return false;
	}
	
	Aws::Auth::AWSCredentials credentials;
	credentials.SetAWSAccessKeyId(accessKey.c_str());
	credentials.SetAWSSecretKey(secretKey.c_str());

	Aws::Client::ClientConfiguration config;
	config.region = Aws::String(region.c_str());
	
	std::string hwid = AntiCrack::GetHardwareID();

	std::shared_ptr<Aws::IOStream> payload = Aws::MakeShared<Aws::StringStream>("FunctionTest");
	Aws::Utils::Json::JsonValue json;
	json.WithString("operation", "auth");
	json.WithString("name", name.c_str());
	json.WithString("secret_key", secretKey.c_str());
	json.WithString("access_key", accessKey.c_str());
	json.WithString("hwid", hwid.c_str());
	*payload << json.View().WriteReadable();

	auto client = Aws::MakeShared<Aws::Lambda::LambdaClient>("alloc_tag", credentials, config);
	Aws::Lambda::Model::InvokeRequest invokeRequest;
	invokeRequest.SetFunctionName("lview-auth");
	invokeRequest.SetInvocationType(Aws::Lambda::Model::InvocationType::RequestResponse);
	invokeRequest.SetLogType(Aws::Lambda::Model::LogType::Tail);
	invokeRequest.SetBody(payload);
	invokeRequest.SetContentType("application/javascript");

	auto outcome = client->Invoke(invokeRequest);
	if (!outcome.IsSuccess()) {
		printf("[!] Access denied.\n");

		auto err = outcome.GetError();
		printf(err.GetExceptionName().c_str());
		return false;
	}

	auto& result = outcome.GetResult();
	Aws::Utils::Json::JsonValue resultJson(result.GetPayload());
	int statusCode = resultJson.View().GetInteger("status");
	Aws::String msg = resultJson.View().GetString("msg");

	if (statusCode != 200) {
		printf("[!] Server authentication failed: %s\n", msg.c_str());
		return false;
	}
	printf("[+] Server authentication succeeded: %s\n", msg.c_str());

	return true;
}
*/
