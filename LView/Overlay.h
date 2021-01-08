#pragma once
#include "Structs.h"
#include "LeagueMemoryReader.h"

#include <chrono>
#include <map>
#include <list>

#include "windows.h"
#include "imgui.h"
#include "imgui_impl_dx11.h"
#include "imgui_impl_win32.h"

#include <boost/python.hpp>
#include "Python.h"

#include "ConfigSet.h"
#include "ScriptManager.h"
#include "PyGame.h"

#include <dinput.h>
#include <dxgi1_3.h>
#include <d3d11_2.h>
#include <dcomp.h>

#include "PyImguiInterface.h"

using namespace std::chrono;
using namespace boost::python;

/// Manages the overlay of the cheat. Also manages the executing scripts.
class Overlay {

public:
	               Overlay();
	void           Init();
	void           GameStart(MemSnapshot& memSnapshot);

	void           StartFrame();
	void           Update(MemSnapshot& memSnapshot);
	void           RenderFrame();

	bool           IsVisible();
	void           Hide();
	void           Show();

private:
	void           DrawUI(MemSnapshot& memSnapshot);
	void           DrawOverlayWindows(PyGame& state);
	void           DrawScripts(PyGame& state, MemSnapshot& memSnapshot);
	void           DrawDevStuff(MemSnapshot& memSnapshot);
	
	void           DrawScriptError(std::shared_ptr<Script>& script);
	void           DrawScriptCommonSettings(std::shared_ptr<Script>& script, int id);

	static bool    CreateDeviceD3D(HWND hWnd);
	static void    CleanupDeviceD3D();
	static void    CreateRenderTarget();
	static void    CleanupRenderTarget();
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


private: 
	HWND                               hWindow;
	bool                               isWindowVisible = true;

	// DirectX stuff
	static ID3D11Device*               g_pd3dDevice;
	static ID3D11DeviceContext*        g_pd3dDeviceContext;
	static IDXGISwapChain1*            g_pSwapChain;
	static ID3D11RenderTargetView*     g_mainRenderTargetView;

	ConfigSet&                         configs;

	ScriptManager                      scriptManager;
	PyImguiInterface                   imguiInterface;

	// Some simple benchmarks
	float                              renderTimeMs;
	float                              processTimeMs;
};