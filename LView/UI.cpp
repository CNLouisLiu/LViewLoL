#include "UI.h"
#include "Utils.h"
#include "Structs.h"
#include "LeagueMemoryReader.h"
#include "Benchmark.h"
#include "PyGame.h"

#include <string>
#include <list>

LPDIRECT3D9                        UI::pD3D = NULL;
LPDIRECT3DDEVICE9                  UI::pd3dDevice = NULL;
D3DPRESENT_PARAMETERS              UI::d3dpp = {};

std::string RandomString(const int len) {

	std::string tmp_s;
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	srand((time_t)time(0));
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];


	return tmp_s;
}

UI::UI(): configs(*(ConfigSet::Get())){
}

void UI::Init() {

	// Create transparent window
	std::string windowClassName = RandomString(10);
	std::string windowName = RandomString(10);
	SetConsoleTitleA(windowName.c_str());
	
	// Create window with random name & class name
	WNDCLASSEXA wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, windowClassName.c_str(), NULL };
	RegisterClassExA(&wc);
	hWindow = CreateWindowExA(
		WS_EX_TOPMOST | WS_EX_NOACTIVATE | WS_EX_LAYERED,
		windowClassName.c_str(), windowName.c_str(),
		WS_POPUP,
		1, 1, 1920, 1080,
		nullptr, nullptr, GetModuleHandle(0), nullptr);

	ShowWindow(hWindow, SW_SHOW);
	
	// Make the window a little bit transparent
	SetLayeredWindowAttributes(hWindow, RGB(0, 0, 0), 200, LWA_COLORKEY | LWA_ALPHA);

	if (hWindow == NULL) {
		throw WinApiException("Failed to create overlay window");
	}

	// Initialize Direct3D
	if (!CreateDeviceD3D(hWindow))
	{
		CleanupDeviceD3D();
		UnregisterClassA(wc.lpszClassName, wc.hInstance);
		throw std::runtime_error("Failed to create D3D device");
	}

	// Setup imgui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigWindowsMoveFromTitleBarOnly = true;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	// Setup Platform/Renderer backends
	ImGui_ImplWin32_Init(hWindow);
	ImGui_ImplDX9_Init(pd3dDevice);

	ImGui::GetStyle().Alpha = 1.f;
}

void UI::GameStart(MemSnapshot& memSnapshot)
{
	scriptManager.LoadAll(configs.GetStr("scriptsFolder", "."), memSnapshot.localChampion->name);
}

void UI::RenderUI(MemSnapshot& memSnapshot) {

	high_resolution_clock::time_point timeBefore;
	duration<float, std::milli> timeDuration;

	PyGame state = PyGame::ConstructFromMemSnapshot(memSnapshot);

	auto io = ImGui::GetIO();
	ImDrawList* overlayDrawList, *minimapDrawList;

	ImGui::SetNextWindowSize(io.DisplaySize);
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::Begin("##Overlay", nullptr,
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoScrollbar |
		ImGuiWindowFlags_NoSavedSettings |
		ImGuiWindowFlags_NoInputs |
		ImGuiWindowFlags_NoBackground
	);
	state.overlay = ImGui::GetWindowDrawList();
	ImGui::End();

	// Draw minimap overlay
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 2.0f);
	ImGui::SetNextWindowBgAlpha(0.0f);
	ImGui::Begin("Minimap Overlay", nullptr,
		ImGuiWindowFlags_NoScrollbar
	);
	state.minimapPos = ImGui::GetWindowPos();
	state.minimapSize = ImGui::GetWindowSize();
	ImGui::End();
	ImGui::PopStyleVar();

	ImGui::ShowDemoWindow();

	ImGui::Begin("Settings");
	ImGui::TextColored(Colors::CYAN, "LVIEW (External RPM Scripting Engine) by leryss");
	
	if (ImGui::Button("Save all script settings")) {
		scriptManager.CollectAllScriptConfigs();
		configs.SaveToFile();
	}
	ImGui::SameLine();
	if (ImGui::Button("Reload all scripts")) {
		GameStart(memSnapshot);
	}

	ImGui::Text("Script Settings");
	int idAboutNode = 10000;
	for (std::shared_ptr<Script>& script : scriptManager.activeScripts) {
		idAboutNode++;

		// If we got any load/execution script error we should print it in bright red
		if (!script->loadError.empty() || !script->execError.empty()) {
			ImGui::PushStyleColor(ImGuiCol_Header, Colors::RED);
			if (ImGui::CollapsingHeader(script->name.c_str())) {
				if (ImGui::Button("Reload script"))
					scriptManager.ReloadScript(script);

				ImGui::TextColored(Colors::RED, script->loadError.c_str());
				ImGui::TextColored(Colors::RED, script->execError.c_str());
			}
			ImGui::PopStyleColor();
		}
		// No error script can execute freely
		else {

			// Gray out disabled cheat
			bool shouldPopColor = false;
			if (!script->enabled) {
				ImGui::PushStyleColor(ImGuiCol_Header, Colors::GRAY);
				shouldPopColor = true;
			} else
				script->ExecUpdate(state, imguiInterface);

			if (ImGui::CollapsingHeader(script->name.c_str())) {

				ImGui::Indent(16.0f);

				// Draw general script settings
				if (ImGui::TreeNode(&idAboutNode, "About")) {
					ImGui::LabelText("Author", script->author.c_str());
					ImGui::TextWrapped(script->description.c_str());
					ImGui::TreePop();
				}
				if (ImGui::Button("Reload script"))
					scriptManager.ReloadScript(script);
				ImGui::SameLine();
				if (ImGui::Button("Save settings")) {
					scriptManager.CollectScriptConfigs(script);
					configs.SaveToFile();
				}
				ImGui::Checkbox("Enabled", &script->enabled);
				ImGui::Separator();

				// Call script to draw its settings
				script->ExecDrawSettings(state, imguiInterface);
				
				ImGui::Unindent();
			}
			if(shouldPopColor)
				ImGui::PopStyleColor();
		}

	}
	ImGui::Separator();

	ImGui::Text("Dev Stuff");
	if (ImGui::CollapsingHeader("Benchmarks")) {
		float readMemoryTime = memSnapshot.benchmark->readChampsMs + memSnapshot.benchmark->readMobsMs + memSnapshot.benchmark->readRendererMs + memSnapshot.benchmark->readTurretsMs;
		float totalMs = readMemoryTime + renderTimeMs + processTimeMs;

		ImGui::DragFloat("Total Time (ms)", &totalMs);
		ImGui::DragFloat("Render UI Time (ms)", &renderTimeMs);
		ImGui::DragFloat("Total Scripts Time (ms)", &processTimeMs);
		ImGui::DragFloat("Read Memory Time (ms)", &readMemoryTime);

		if (ImGui::TreeNode("Memory read time (ms)")) {
			ImGui::DragFloat("Read champions", &memSnapshot.benchmark->readChampsMs);
			ImGui::DragFloat("Read mobs",      &memSnapshot.benchmark->readMobsMs);
			ImGui::DragFloat("Read renderer",  &memSnapshot.benchmark->readRendererMs);
			ImGui::DragFloat("Read turrets",   &memSnapshot.benchmark->readTurretsMs);
			ImGui::TreePop();
		}

		if (ImGui::TreeNode("Script process time (ms)")) {
			for (std::shared_ptr<Script>& script : scriptManager.activeScripts) {
				float ms = script->updateTimeMs.count();
				ImGui::DragFloat(script->name.c_str(), &ms);
			}
			ImGui::TreePop();
		}
	}

	ImGui::End();
}

void UI::Update(MemSnapshot& memSnapshot, bool skipRender) {
	
	high_resolution_clock::time_point timeBefore;
	duration<float, std::milli> timeDuration;

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	
	if (skipRender) {
		// Poll and handle messages (inputs, window resize, etc.)
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	// Start the Dear ImGui frame
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	timeBefore = high_resolution_clock::now();

	if (skipRender) {
		RenderUI(memSnapshot);
	}

	timeDuration = high_resolution_clock::now() - timeBefore;	
	processTimeMs = timeDuration.count();
	
	// Render
	timeBefore = high_resolution_clock::now();

	pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(0, 0, 0, 0), 1.0f, 0);
	if (pd3dDevice->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		pd3dDevice->EndScene();

	}
	HRESULT result = pd3dDevice->Present(NULL, NULL, NULL, NULL);

	// Handle loss of D3D9 device
	if (result == D3DERR_DEVICELOST && pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
		ResetDevice();

	timeDuration = high_resolution_clock::now() - timeBefore;
	renderTimeMs = timeDuration.count();
}


// Helper functions
bool UI::CreateDeviceD3D(HWND hWnd)
{
	if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return false;

	// Create the D3DDevice
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	//d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;       // Present with vsync
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
	if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &pd3dDevice) < 0)
		return false;

	return true;
}

void UI::CleanupDeviceD3D()
{
	if (pd3dDevice) { pd3dDevice->Release(); pd3dDevice = NULL; }
	if (pD3D) { pD3D->Release(); pD3D = NULL; }
}

void UI::ResetDevice()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	HRESULT hr = pd3dDevice->Reset(&d3dpp);
	if (hr == D3DERR_INVALIDCALL)
		IM_ASSERT(0);
	ImGui_ImplDX9_CreateDeviceObjects();
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
LRESULT WINAPI UI::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			d3dpp.BackBufferWidth = LOWORD(lParam);
			d3dpp.BackBufferHeight = HIWORD(lParam);
			ResetDevice();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		return 0;
	}
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}