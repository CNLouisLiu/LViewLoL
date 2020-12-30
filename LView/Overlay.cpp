#include "Overlay.h"
#include "Utils.h"
#include "Structs.h"
#include "LeagueMemoryReader.h"
#include "Benchmark.h"

#include <string>
#include <list>

#define HCheck(x, m) if(x != S_OK) { throw std::runtime_error(format("DirectX: Failed at %s. Error code: %d\n", m, MAKE_HRESULT(1, _FACDXGI, X))); }

ID3D11Device*            Overlay::g_pd3dDevice            = NULL;
ID3D11DeviceContext*     Overlay::g_pd3dDeviceContext     = NULL;
IDXGISwapChain1*         Overlay::g_pSwapChain            = NULL;
ID3D11RenderTargetView*  Overlay::g_mainRenderTargetView  = NULL;

std::string format(const char* c, const char* args...) {
	char buff[200];
	sprintf_s(buff, c, args);

	return std::string(buff);
}

std::string RandomString(const int len) {

	std::string tmp_s;
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	srand((unsigned int)time(0));
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];


	return tmp_s;
}

Overlay::Overlay(): configs(*(ConfigSet::Get())){
}

void Overlay::Init() {

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

	if (hWindow == NULL) {
		throw WinApiException("Failed to create overlay window");
	}
	
	ShowWindow(hWindow, SW_SHOW);
	//SetLayeredWindowAttributes(hWindow, RGB(0, 0, 0), 255, LWA_COLORKEY); 


	// Initialize Direct3D
	if (!CreateDeviceD3D(hWindow))
	{
		CleanupDeviceD3D();
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
	ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

	ImGui::GetStyle().Alpha = 1.f;
}

void Overlay::GameStart(MemSnapshot& memSnapshot)
{
	scriptManager.LoadAll(configs.GetStr("scriptsFolder", "."), memSnapshot.localChampion->name);
}

void Overlay::DrawUI(MemSnapshot& memSnapshot) {

	high_resolution_clock::time_point timeBefore;

	PyGame state = PyGame::ConstructFromMemSnapshot(memSnapshot);

	DrawOverlayWindows(state);
	DrawScripts(state, memSnapshot);
}

void Overlay::DrawOverlayWindows(PyGame& state)
{
	// Draw game overlay (used for primitive rendering)
	auto io = ImGui::GetIO();
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
}

void Overlay::DrawScripts(PyGame& state, MemSnapshot& memSnapshot)
{
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
	int idNode = 10000;
	for (std::shared_ptr<Script>& script : scriptManager.activeScripts) {
		idNode++;

		// If we got any load/execution script error we should print it in bright red
		if (!script->loadError.empty() || !script->execError.empty()) {
			DrawScriptError(script);
		}
		else {

			// Gray out disabled cheat
			bool skippedExecution = false;
			if (!script->enabled) {
				ImGui::PushStyleColor(ImGuiCol_Header, Colors::GRAY);
				skippedExecution = true;
			}
			else
				script->ExecUpdate(state, imguiInterface);

			if (ImGui::CollapsingHeader(script->name.c_str())) {
				ImGui::Indent(16.0f);

				DrawScriptCommonSettings(script, idNode);
				script->ExecDrawSettings(state, imguiInterface);

				ImGui::Unindent();
			}

			if (skippedExecution)
				ImGui::PopStyleColor();
		}

	}
	ImGui::Separator();
	DrawDevStuff(memSnapshot);

	ImGui::End();
}

void Overlay::DrawDevStuff(MemSnapshot & memSnapshot)
{
	ImGui::Text("Dev Stuff");
	if (ImGui::CollapsingHeader("Benchmarks")) {
		float readMemoryTime = memSnapshot.benchmark->readChampsMs +
			memSnapshot.benchmark->readMobsMs +
			memSnapshot.benchmark->readRendererMs + 
			memSnapshot.benchmark->readTurretsMs +
			memSnapshot.benchmark->readMissilesMs;

		float totalMs = readMemoryTime + renderTimeMs + processTimeMs;

		ImGui::DragFloat("Total Time (ms)", &totalMs);
		ImGui::DragFloat("Render UI Time (ms)", &renderTimeMs);
		ImGui::DragFloat("Total Scripts Time (ms)", &processTimeMs);
		ImGui::DragFloat("Read Memory Time (ms)", &readMemoryTime);

		if (ImGui::TreeNode("Memory read time (ms)")) {
			ImGui::DragFloat("Read champions", &memSnapshot.benchmark->readChampsMs);
			ImGui::DragFloat("Read mobs", &memSnapshot.benchmark->readMobsMs);
			ImGui::DragFloat("Read renderer", &memSnapshot.benchmark->readRendererMs);
			ImGui::DragFloat("Read turrets", &memSnapshot.benchmark->readTurretsMs);
			ImGui::DragFloat("Read missiles", &memSnapshot.benchmark->readMissilesMs);
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
}

void Overlay::DrawScriptError(std::shared_ptr<Script>& script)
{
	ImGui::PushStyleColor(ImGuiCol_Header, Colors::RED);
	if (ImGui::CollapsingHeader(script->name.c_str())) {
		if (ImGui::Button("Reload script"))
			scriptManager.ReloadScript(script);

		ImGui::TextColored(Colors::RED, script->loadError.c_str());
		ImGui::TextColored(Colors::RED, script->execError.c_str());
	}
	ImGui::PopStyleColor();
}

void Overlay::DrawScriptCommonSettings(std::shared_ptr<Script>& script, int id)
{
	if (ImGui::TreeNode(&id, "About")) {
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
}

void Overlay::StartFrame()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
	{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void Overlay::Update(MemSnapshot& memSnapshot) {

	// Simple check to see if game ended
	if (memSnapshot.champions.size() == 0 || !isWindowVisible)
		return;

	auto timeBefore = high_resolution_clock::now();

	DrawUI(memSnapshot);

	duration<float, std::milli> timeDuration = high_resolution_clock::now() - timeBefore;	
	processTimeMs = timeDuration.count();
}

void Overlay::RenderFrame()
{
	static ImVec4 clear_color = ImVec4(0.f, 0.f, 0.f, 0.f);

	// Render
	auto timeBefore = high_resolution_clock::now();
	
	ImGui::EndFrame();
	ImGui::Render();
	g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
	g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, (float*)&clear_color);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	g_pSwapChain->Present(0, 0);

	duration<float, std::milli> timeDuration = high_resolution_clock::now() - timeBefore;
	renderTimeMs = timeDuration.count();
}

bool Overlay::IsVisible()
{
	return isWindowVisible;
}

void Overlay::Hide()
{
	ShowWindow(hWindow, SW_HIDE);
	isWindowVisible = false;
}

void Overlay::Show()
{
	ShowWindow(hWindow, SW_SHOW);
	isWindowVisible = true;
}

bool Overlay::CreateDeviceD3D(HWND hWnd)
{
	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	HCheck(D3D11CreateDevice(
		nullptr,    // Adapter
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,    // Module
		D3D11_CREATE_DEVICE_BGRA_SUPPORT ,
		nullptr, 0, // Highest available feature level
		D3D11_SDK_VERSION,
		&g_pd3dDevice,
		nullptr,    // Actual feature level
		&g_pd3dDeviceContext), "Creating device");

	IDXGIDevice* dxgiDevice;
	HCheck(g_pd3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void **)& dxgiDevice), "Query DXGI Device");

	IDXGIAdapter * dxgiAdapter = 0;
	HCheck(dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void **)& dxgiAdapter), "Get DXGI Adapter");

	IDXGIFactory2 * dxgiFactory = 0;
	HCheck(dxgiAdapter->GetParent(__uuidof(IDXGIFactory2), (void **)& dxgiFactory), "Get DXGI Factory");

	// Create swap chain with alpha mode premultiplied
	DXGI_SWAP_CHAIN_DESC1 description = {};
	description.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	description.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
	description.BufferCount = 2;
	description.SampleDesc.Count = 1;
	description.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;
	description.Scaling = DXGI_SCALING_STRETCH;
	RECT rect = {};
	GetClientRect(hWnd, &rect);
	description.Width = rect.right - rect.left;
	description.Height = rect.bottom - rect.top;

	HCheck(dxgiFactory->CreateSwapChainForComposition(dxgiDevice,
		&description,
		nullptr,
		&g_pSwapChain), "Create swap chain");
		
	// Create Direct Composition shits. This is the only way to make the UI not lag the game and itself.
	IDCompositionDevice* dcompDevice;
	DCompositionCreateDevice(
		dxgiDevice,
		__uuidof(dcompDevice),
		(void**)&dcompDevice);

	IDCompositionTarget* target;
	dcompDevice->CreateTargetForHwnd(hWnd,
		true,
		&target);

	IDCompositionVisual* visual;
	dcompDevice->CreateVisual(&visual);
	visual->SetContent(g_pSwapChain);
	target->SetRoot(visual);
	dcompDevice->Commit();

	CreateRenderTarget();
	return true;
}

void Overlay::CleanupDeviceD3D()
{
	CleanupRenderTarget();
	if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
	if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
}

void Overlay::CreateRenderTarget()
{
	ID3D11Resource* pBackBuffer;
	if(S_OK != g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer)))
		throw std::runtime_error("Failed to retrieve DX11 swap chain buffer");
	if (S_OK != g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView))
		throw std::runtime_error("Failed to create DX11 render target");
	pBackBuffer->Release();
}

void Overlay::CleanupRenderTarget()
{
	if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI Overlay::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			CleanupRenderTarget();
			g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
			CreateRenderTarget();
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