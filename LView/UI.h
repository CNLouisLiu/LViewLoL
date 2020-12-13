#pragma once
#include "Structs.h"
#include "LeagueMemoryReader.h"
#include "BaseView.h"

#include <chrono>
#include <map>
#include <list>

#include "windows.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

#include <d3d9.h>
#include <dinput.h>


using namespace std::chrono;

class UI {

public:
	               UI(std::list<BaseView*> views);
	void           Start();
	void           Update(MemSnapshot& memSnapshot, bool skipRender);

private:
	void           RenderUI(MemSnapshot& memSnapshot);
	bool           CreateDeviceD3D(HWND hWnd);
	void           CleanupDeviceD3D();
	static void    ResetDevice();
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private: 
	HWND                               hWindow;

	Renderer                           renderer;
	std::list<BaseView*>               views;

	// DirectX stuff
	static LPDIRECT3D9                 pD3D;
	static LPDIRECT3DDEVICE9           pd3dDevice;
	static D3DPRESENT_PARAMETERS       d3dpp;

	ConfigSet                          configs;
	std::string                        configFilePath = std::string("config.ini");

	MiscToolbox                        miscToolbox;
};