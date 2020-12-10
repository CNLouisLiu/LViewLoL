#include "UI.h"
#include "Utils.h"
#include "Structs.h"
#include "LeagueMemoryReader.h"
#include <string>
#include <list>

LPDIRECT3D9                        UI::pD3D = NULL;
LPDIRECT3DDEVICE9                  UI::pd3dDevice = NULL;
D3DPRESENT_PARAMETERS              UI::d3dpp = {};

UI::UI(std::list<BaseView*> views) {
	this->views = views;
	for (auto it = views.begin(); it != views.end(); ++it)
		viewBenchmarks[*it] = ViewBenchmark();
}

void UI::Start() {


	// Create transparent window
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, L"LVIEWCLASS", NULL };
	RegisterClassEx(&wc);
	hWindow = CreateWindowExA(
		WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_NOACTIVATE, //WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT
		"LVIEWCLASS", "LVIEW",
		WS_POPUP,
		1, 1, 1920, 1080,
		nullptr, nullptr, GetModuleHandle(0), nullptr);

	SetLayeredWindowAttributes(hWindow, 0, 0, LWA_ALPHA);
	SetLayeredWindowAttributes(hWindow, 0, RGB(0, 0, 0), LWA_COLORKEY);


	if (hWindow == NULL) {
		throw WinApiException("Failed to create overlay window");
	}

	// Initialize Direct3D
	if (!CreateDeviceD3D(hWindow))
	{
		CleanupDeviceD3D();
		UnregisterClass(wc.lpszClassName, wc.hInstance);
		throw std::runtime_error("Failed to create D3D device");
	}

	// Show the window
	ShowWindow(hWindow, SW_SHOWDEFAULT);
	UpdateWindow(hWindow);
	
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

	// Make some fonts
	fontConfigSmall.SizePixels = 10;
	fontConfigNormal.SizePixels = 13;
	fontSmall = io.Fonts->AddFontDefault(&fontConfigSmall);
	fontNormal = io.Fonts->AddFontDefault(&fontConfigNormal);

	// Load configs
	configs.LoadFromFile(configFilePath);
	for (auto it = views.begin(); it != views.end(); ++it) {
		BaseView* view = *it;
		configs.SetPrefixKey(view->GetName());
		view->OnLoadSettings(configs);
	}

}

void UI::RenderUI(LeagueMemoryReader& reader) {

	high_resolution_clock::time_point timeBefore;
	duration<float, std::milli> timeDuration;

	// Draw world space overlay
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
	ImDrawList* list = ImGui::GetWindowDrawList();
	for (auto it = views.begin(); it != views.end(); ++it) {
		BaseView* view = *it;
		if (view->enabled) {
			timeBefore = high_resolution_clock::now();
			view->DrawWorldSpaceOverlay(reader, list, *this);
			timeDuration = high_resolution_clock::now() - timeBefore;
			viewBenchmarks[view].drawWorldOverlayMs = timeDuration.count();
		}
	}
	ImGui::End();

	// Draw minimap overlay
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 2.0f);
	ImGui::SetNextWindowBgAlpha(0.0f);
	ImGui::Begin("Minimap Overlay", nullptr,
		ImGuiWindowFlags_NoScrollbar
	);
	list = ImGui::GetWindowDrawList();
	for (auto it = views.begin(); it != views.end(); ++it) {
		BaseView* view = *it;
		if (view->enabled) {
			timeBefore = high_resolution_clock::now();
			view->DrawMinimapOverlay(reader, list, *this);
			timeDuration = high_resolution_clock::now() - timeBefore;
			viewBenchmarks[view].drawMinimapOverlayMs = timeDuration.count();
		}
	}

	ImGui::End();
	ImGui::PopStyleVar();

	// Draw settings and other panels
	ImGui::Begin("Settings");
	ImGui::TextColored(Colors::Cyan, "LVIEW (External RPM Tool) by leryss");
	ImGui::Separator();

	if (ImGui::Button("Save Settings")) {
		for (auto it = views.begin(); it != views.end(); ++it) {
			BaseView* view = *it;
			configs.SetPrefixKey(view->GetName());
			view->OnSaveSettings(configs);
		}
		configs.SaveToFile(configFilePath);
	}

	for (auto it = views.begin(); it != views.end(); ++it) {
		BaseView* view = *it;
		if (ImGui::CollapsingHeader(view->GetName())) {
			ImGui::Checkbox("Enabled", &view->enabled);

			timeBefore = high_resolution_clock::now();
			view->DrawSettings(reader, *this);
			timeDuration = high_resolution_clock::now() - timeBefore;
			viewBenchmarks[view].drawSettingsMs = timeDuration.count();
		}

		if (view->enabled) {
			timeBefore = high_resolution_clock::now();
			view->DrawPanel(reader, *this);
			timeDuration = high_resolution_clock::now() - timeBefore;
			viewBenchmarks[view].drawPanelMs = timeDuration.count();
		}
	}
	ImGui::End();
}

void UI::Update(LeagueMemoryReader& reader) {
	
	bool shouldRenderUI = reader.IsLeagueWindowActive();
	high_resolution_clock::time_point timeBefore;
	duration<float, std::milli> timeDuration;

	if (shouldRenderUI) {
		MSG msg;
		ZeroMemory(&msg, sizeof(MSG));

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
	ImGui::PushFont(fontNormal);

	timeBefore = high_resolution_clock::now();

	if (shouldRenderUI)
		RenderUI(reader);

	timeDuration = high_resolution_clock::now() - timeBefore;
	generalBenchmarks.processTimeMs = timeDuration.count();

	ImGui::PopFont();
	
	// Render
	timeBefore = high_resolution_clock::now();
	
	pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);


	ImVec4 clear_color = ImVec4(0.f, 0.f, 0.f, 0.0f);
	D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x*255.0f), (int)(clear_color.y*255.0f), (int)(clear_color.z*255.0f), (int)(clear_color.w*255.0f));
	pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
	if (pd3dDevice->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		pd3dDevice->EndScene();
	}
	HRESULT result = pd3dDevice->Present(NULL, NULL, NULL, NULL);

	timeDuration = high_resolution_clock::now() - timeBefore;
	generalBenchmarks.renderTimeMs = timeDuration.count();

	// Handle loss of D3D9 device
	if (result == D3DERR_DEVICELOST && pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
		ResetDevice();

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
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
	//g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
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