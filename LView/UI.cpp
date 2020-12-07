#include "UI.h"
#include "Utils.h"
#include "Structs.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include "LeagueProcessHook.h"
#include <d3d9.h>
#include <dinput.h>
#include <string>
#include <list>

#define DIRECTINPUT_VERSION 0x0800

// Data
static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

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

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	// Setup Platform/Renderer backends
	ImGui_ImplWin32_Init(hWindow);
	ImGui_ImplDX9_Init(g_pd3dDevice);

}

void DrawSpellButton(Spell spell, float gameTime) {
	float remainingCooldown = spell.GetRemainingCooldown(gameTime);
	float hue = 0.25f; // GREEN
	if (remainingCooldown > 10.f)
		hue = 0.f;  // RED
	else if (remainingCooldown > 0.1f)
		hue = 0.125f; // YELLOW

	ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(hue, 1.f, 0.5f));
	ImGui::Button(spell.GetRemainingCooldownStr(gameTime));
	ImGui::PopStyleColor(1);
	ImGui::SameLine();
}

void DrawSpellButton(Spell spell, float gameTime, ImDrawList* drawList, ImVec2 position) {
	float remainingCooldown = spell.GetRemainingCooldown(gameTime);
	float hue = 0.25f; // GREEN
	if (remainingCooldown > 10.f)
		hue = 0.f;  // RED
	else if (remainingCooldown > 0.1f)
		hue = 0.125f; // YELLOW

	drawList->AddRectFilled(ImVec2(position.x -5, position.y), ImVec2(position.x + 25, position.y + 15), ImColor::HSV(hue, 1.f, 0.5f));
	if (remainingCooldown > 0.f)
		drawList->AddText(position, ImColor::HSV(0.f, 0.f, 1.f), std::to_string((int)remainingCooldown).c_str());
	else
		drawList->AddText(position, ImColor::HSV(0.f, 0.f, 1.f), gSpellTypeName[(int)spell.type]);
}


void DrawSpellTrackerPanel(LeagueProcessHook reader) {
	ImGui::Begin("SpellTracker");
	for (int i = 0; i < reader.numChampions; ++i) {

		Champion it = reader.champions[i];
		if (it.team == 100) // Skip allies
			continue;

		if (ImGui::TreeNode(it.name.c_str())) {

			ImGui::BeginGroup();

			DrawSpellButton(it.Q, reader.gameTime);
			DrawSpellButton(it.W, reader.gameTime);
			DrawSpellButton(it.E, reader.gameTime);
			DrawSpellButton(it.R, reader.gameTime);
			DrawSpellButton(it.D, reader.gameTime);
			DrawSpellButton(it.F, reader.gameTime);

			ImGui::EndGroup();
			ImGui::TreePop();
		}
	}
	ImGui::End();
}

void DrawSpellTrackerOnChampions(LeagueProcessHook reader) {


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

	for (int i = 0; i < reader.numChampions; ++i) {
		Champion champ = reader.champions[i];
		Vector2 pos = reader.renderer.WorldToScreen(champ.position);
		ImVec2 imPos = ImVec2(pos.x - 60, pos.y);
		
		
		DrawSpellButton(champ.Q, reader.gameTime, list, imPos);
		imPos.x += 35;

		DrawSpellButton(champ.W, reader.gameTime, list, imPos);
		imPos.x += 35;

		DrawSpellButton(champ.E, reader.gameTime, list, imPos);
		imPos.x += 35;

		DrawSpellButton(champ.R, reader.gameTime, list, imPos);
		imPos.x += 35;
	}
	ImGui::End();
}

void UI::Update(LeagueProcessHook reader) {
	
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	// Poll and handle messages (inputs, window resize, etc.)
	if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// Start the Dear ImGui frame
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	DrawSpellTrackerPanel(reader);
	DrawSpellTrackerOnChampions(reader);


	// Render
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);


	ImVec4 clear_color = ImVec4(0.f, 0.f, 0.f, 0.0f);
	D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x*255.0f), (int)(clear_color.y*255.0f), (int)(clear_color.z*255.0f), (int)(clear_color.w*255.0f));
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
	if (g_pd3dDevice->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		g_pd3dDevice->EndScene();
	}
	HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

	// Handle loss of D3D9 device
	if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
		ResetDevice();

}


// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
	if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return false;

	// Create the D3DDevice
	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
	//g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
	if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
		return false;

	return true;
}

void CleanupDeviceD3D()
{
	if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
	if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}

void ResetDevice()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
	if (hr == D3DERR_INVALIDCALL)
		IM_ASSERT(0);
	ImGui_ImplDX9_CreateDeviceObjects();
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			g_d3dpp.BackBufferWidth = LOWORD(lParam);
			g_d3dpp.BackBufferHeight = HIWORD(lParam);
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