#include <pch.h>
#include <base.h>

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK Base::Hooks::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_KEYDOWN || uMsg == WM_KEYUP)
		Data::WMKeys[wParam] = uMsg;

	switch (uMsg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case Data::Keys::Menu:
			Data::ShowMenu = !Data::ShowMenu;
			break;
		case Data::Keys::Unload:
			Base::Unload();
			break;
		}
	}

	if (Data::ShowMenu && Data::InitSwapBuffers)
	{
		switch (uMsg)
		{
		case WM_LBUTTONDOWN: 
		case WM_LBUTTONDBLCLK:
		case WM_RBUTTONDOWN: 
		case WM_RBUTTONDBLCLK:
		case WM_MBUTTONDOWN: 
		case WM_MBUTTONDBLCLK:
		case WM_XBUTTONDOWN: 
		case WM_XBUTTONDBLCLK:
		case WM_LBUTTONUP:
		case WM_RBUTTONUP:
		case WM_MBUTTONUP:
		case WM_XBUTTONUP:
		case WM_MOUSEWHEEL:
		case WM_MOUSEHWHEEL:
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP:
		case WM_CHAR:
		case WM_SETCURSOR:
		case WM_DEVICECHANGE:
			ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
			return true;
		default: std::cout << "msg: " << uMsg << std::endl;  break;
		}
	}

	SDL_ShowCursor(-1);

	return CallWindowProc(Data::oWndProc, hWnd, uMsg, wParam, lParam);
}