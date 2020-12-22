#pragma once
#include "Structs.h"
#include "LeagueMemoryReader.h"

#include <chrono>
#include <map>
#include <list>

#include "windows.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

#include <boost/python.hpp>
#include "Python.h"

#include "ConfigSet.h"
#include "ScriptManager.h"

#include <d3d9.h>
#include <dinput.h>

#include "PyImguiInterface.h"

using namespace std::chrono;
using namespace boost::python;

class UI {

public:
	               UI();
	void           Init();
	void           GameStart(MemSnapshot& memSnapshot);
	void           Update(MemSnapshot& memSnapshot, bool skipRender);

private:
	void           RenderUI(MemSnapshot& memSnapshot);
	bool           CreateDeviceD3D(HWND hWnd);
	void           CleanupDeviceD3D();
	static void    ResetDevice();
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


private: 
	HWND                               hWindow;

	GameRenderer                       renderer;

	// DirectX stuff
	static LPDIRECT3D9                 pD3D;
	static LPDIRECT3DDEVICE9           pd3dDevice;
	static D3DPRESENT_PARAMETERS       d3dpp;

	ConfigSet&                         configs;

	ScriptManager                      scriptManager;
	PyImguiInterface                   imguiInterface;

	// Some simple benchmarks
	float                              renderTimeMs;
	float                              processTimeMs;
};