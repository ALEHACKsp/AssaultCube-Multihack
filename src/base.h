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
		extern HMODULE               hModule;
		extern HWND                  hWindow;
		extern RECT                  WindowRect;
		extern int                   WindowWidth;
		extern int                   WindowHeight;
		extern mem::module_t         m_opengl;
		extern mem::module_t         m_ac_client;
		extern mem::module_t         m_sdl;
		extern mem::voidptr_t        pSwapBuffers;
		extern mem::voidptr_t        pShowCursor;
		extern mem::voidptr_t        p_c2sinfo;
		extern mem::voidptr_t        p_servertoclient;
		extern mem::voidptr_t        p_movelocalplayer;
		extern mem::voidptr_t        p_drawcrosshair;
		extern mem::voidptr_t        p_attackphysics;
		extern mem::voidptr_t        p_attackphysics_ret;
		extern mem::voidptr_t        p_drawscope;
		extern mem::voidptr_t        p_dodamage;
		extern mem::voidptr_t        p_dodamage2;
		extern mem::voidptr_t        p_checkheadshot;
		extern SwapBuffers_t         oSwapBuffers;
		extern ShowCursor_t          oShowCursor;
		extern WndProc_t             oWndProc;
		extern c2sinfo_t             o_c2sinfo;
		extern servertoclient_t      o_servertoclient;
		extern movelocalplayer_t     o_movelocalplayer;
		extern drawcrosshair_t       o_drawcrosshair;
		extern attackphysics_t       o_attackphysics;
		extern drawscope_t           o_drawscope;
		extern glDrawRangeElements_t o_glDrawRangeElements;
		extern dodamage_t            o_dodamage;
		extern dodamage2_t           o_dodamage2;
		extern midfunction_t         o_checkheadshot;
		extern mem::size_t           szSwapBuffers;
		extern mem::size_t           szShowCursor;
		extern mem::size_t           sz_c2sinfo;
		extern mem::size_t           sz_servertoclient;
		extern mem::size_t           sz_movelocalplayer;
		extern mem::size_t           sz_drawcrosshair;
		extern mem::size_t           sz_attackphysics;
		extern mem::size_t           sz_drawscope;
		extern mem::size_t           sz_dodamage;
		extern mem::size_t           sz_dodamage2;
		extern mem::size_t           sz_checkheadshot;
		extern bool                  WMKeys[0xFE];
		extern bool                  InitSwapBuffers;
		extern bool                  IsUnloaded;
		extern bool                  ShowMenu;
		extern HGLRC                 glContext;
		extern HGLRC                 oContext;
		extern AC_Client             game;
		extern ImFont*               FontTitle;
		extern ImFont*               FontMenu;
		extern ImFont*               FontHack;
		extern bool                  ShowWatermark;
		extern ImColor               WatermarkColor;

		namespace Settings
		{
			extern bool    EnableCrosshair;
			extern int     CrosshairType;
			extern float   CrosshairLength;
			extern float   CrosshairThickness;
			extern float   CrosshairGap;
			extern bool    CrosshairTop;
			extern bool    CrosshairLeft;
			extern bool    CrosshairBottom;
			extern bool    CrosshairRight;
			extern bool    CrosshairDot;
			extern bool    CrosshairDotFilled;
			extern float   CrosshairColor[4];

			extern bool    EnableEspTeam;
			extern bool    EnableEspEnemy;

			extern bool    EnableEspSnaplines;
			extern bool    EspSnaplinesVisibilityCheck;
			extern float   EspSnaplinesThickness;
			extern float   EspSnaplinesColorTeam[4];
			extern float   EspSnaplinesColorEnemy[4];
			extern float   EspSnaplinesColorTeamVisible[4];
			extern float   EspSnaplinesColorEnemyVisible[4];
			extern int     EspSnaplinesPos;

			extern bool    EnableEspBox;
			extern bool    EspBoxVisibilyCheck;
			extern float   EspBoxThickness;
			extern float   EspBoxColorTeam[4];
			extern float   EspBoxColorFillTeam[4];
			extern float   EspBoxColorEnemy[4];
			extern float   EspBoxColorFillEnemy[4];
			extern float   EspBoxColorTeamVisible[4];
			extern float   EspBoxColorFillTeamVisible[4];
			extern float   EspBoxColorEnemyVisible[4];
			extern float   EspBoxColorFillEnemyVisible[4];

			extern bool    EnableTeleport;
			extern bool    TeleportQueued;
			extern bool    TeleportSaveQueued;
			extern float   TeleportPosition[3];
			extern bool    TeleportForce[3];

			extern bool    EnableNoRecoil;

			extern bool    EnableSpeedhack;
			extern float   SpeedhackValue;

			extern bool    EnableTriggerbot;
			extern bool    TriggerbotToggle;
			extern bool    TriggerbotToggleState;

			extern bool    EnableFlyHack;

			extern bool    EnableNoScope;

			extern bool    EnableTeleportPlayers;
			extern float   TeleportPlayersDistance;
			extern bool    TeleportPlayersTeam;
			extern bool    TeleportPlayersEnemy;

			extern bool    EnableEspHealth;
			extern float   EspHealthColor[4];
			extern float   EspHealthDmgColor[4];

			extern bool    EnableEspArmor;
			extern float   EspArmorColor[4];
			extern float   EspArmorDmgColor[4];

			extern bool    EnableEspName;
			extern float   EspNameColor[4];

			extern bool    EnableBunnyhop;
			extern bool    BunnyhopToggle;
			extern bool    BunnyhopToggleState;

			extern bool    EnableWallhack;

			extern bool    EnableAimbot;
			extern bool    AimbotToggle;
			extern bool    AimbotToggleState;
			extern bool    AimbotSmooth;
			extern float   AimbotSmoothValue;
			extern int     AimbotTargetPreference;

			extern bool    EnableServerSide;
			extern bool    EnableGodmode;
			extern bool    EnableInstantKill;
			extern bool    EnableInfiniteAmmo;
			extern bool    EnableNoGunWait;

			extern bool    EnableAlwaysHeadshot;

			extern bool    EnableInfiniteArmor;

			extern bool    EnableInfiniteHealth;

			extern bool    EnableAutoGuns;
		}

		namespace Keys
		{
			const  UINT    Menu   = VK_INSERT;
			const  UINT    Unload = VK_END;
			const  UINT    Cancel = VK_ESCAPE;
			extern UINT    Bhop;
			extern UINT    Triggerbot;
			extern UINT    TeleportSavePos;
			extern UINT    Teleport;
			extern UINT    Aimbot;
			extern UINT*   ToChange;
		}
	}

	namespace Hacks
	{
		void Teleport();
		void Crosshair();
		void ESP_Snaplines(playerinfo_t* p_info);
		void ESP_Box(playerinfo_t* p_info);
		void NoRecoil();
		void Speedhack();
		void Triggerbot();
		void FlyHack();
		void NoScope();
		void TeleportPlayers(playerent* p_ent);
		void ESP_Info(playerinfo_t* p_info);
		void Bunnyhop();
		void Wallhack(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
		void Aimbot();
		void Godmode();
		void InstantKill();
		void InfiniteAmmo();
		void NoGunWait();
		void AlwaysHeadshot();
		void InfiniteArmor();
		void InfiniteHealth();
		void AutoGuns();
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
		//void drawcrosshair(playerent* p, int n, struct color* c, float size);
		void drawcrosshair(void);
		void attackphysics(void);
		//void drawscope(bool preload)
		void drawscope(void);
		void __stdcall glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
		//void dodamage(int damage, playerent *pl, playerent *actor, int gun, bool gib, bool local)
		void dodamage(void);
		void dodamage2(void);
		void checkheadshot(void);
	}
}