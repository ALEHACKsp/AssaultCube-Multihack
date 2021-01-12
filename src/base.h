#pragma once
#include <pch.h>
#include "game.h"

#define MODULE_OFFSET(mod, offset) (&((char*)mod.base)[offset])

typedef BOOL(__stdcall* SwapBuffers_t)(_In_ HDC hdc);
typedef LRESULT(CALLBACK* WndProc_t) (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
typedef int(SDLCALL* ShowCursor_t)(int toggle);

DWORD WINAPI EntryThread(LPVOID lpReserved);
DWORD WINAPI ExitThread(LPVOID lpReserved);

namespace Base
{
	void Init(HMODULE hMod);
	void Shutdown();
	void Unload();

	namespace Data
	{
		extern HMODULE           hModule;
		extern HWND              hWindow;
		extern mem::module_t     m_opengl;
		extern mem::module_t     m_ac_client;
		extern mem::module_t     m_sdl;
		extern mem::voidptr_t    pSwapBuffers;
		extern mem::voidptr_t    pShowCursor;
		extern mem::voidptr_t    p_c2sinfo;
		extern mem::voidptr_t    p_servertoclient;
		extern mem::voidptr_t    p_movelocalplayer;
		extern SwapBuffers_t     oSwapBuffers;
		extern ShowCursor_t      oShowCursor;
		extern WndProc_t         oWndProc;
		extern c2sinfo_t         o_c2sinfo;
		extern servertoclient_t  o_servertoclient;
		extern movelocalplayer_t o_movelocalplayer;
		extern mem::size_t       szSwapBuffers;
		extern mem::size_t       szShowCursor;
		extern mem::size_t       sz_c2sinfo;
		extern mem::size_t       sz_servertoclient;
		extern mem::size_t       sz_movelocalplayer;
		extern UINT              WMKeys[0xFE];
		extern bool              InitSwapBuffers;
		extern bool              IsUnloaded;
		extern bool              ShowMenu;
		extern HGLRC             glContext;
		extern HGLRC             oContext;
		extern AC_Client         game;

		namespace Settings
		{
			extern bool  TeleportQueued;
			extern bool  TeleportSaveQueued;
			extern float TeleportPosition[3];
			extern bool  TeleportForce[3];
		}

		namespace Keys
		{
			const UINT Menu   = VK_INSERT;
			const UINT Unload = VK_END;
		}
	}

	namespace Hacks
	{
		void Teleport();
	}

	namespace Hooks
	{
		void Init();
		void Shutdown();
		BOOL __stdcall SwapBuffers(_In_ HDC hdc);
		LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		int SDLCALL ShowCursor(int toggle);
		void c2sinfo(playerent* d);
		void servertoclient(int chan, uchar* buf, int len, bool demo);
		void movelocalplayer();
	}
}