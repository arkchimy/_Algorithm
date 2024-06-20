#include "stdafx.h"
#include "WndAPI.h"
#include "Graph.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND Arkchimy_Wnd::hwnd = nullptr;

int Screen_Width = 2580;
int Screen_Height = 1080;
int Wnd_Width = 600;
int Wnd_Height = 600;

RECT gWnd_rt;

Arkchimy_Wnd::Arkchimy_Wnd()
{
	LPCWSTR title = L"길찾기 프로그램";

	WNDCLASSEX wndclass = { sizeof(WNDCLASSEX),
					CS_CLASSDC,
					WndProc,
					0L,
					0L,
					GetModuleHandle(NULL),
					NULL,
					NULL,
					NULL,
					NULL,
					L"윈도우 프로그래밍", // lpszClassName, L-string
					NULL };

	RegisterClassEx(&wndclass);

	gWnd_rt = { 0,0,Wnd_Width,Wnd_Height };
	AdjustWindowRect(&gWnd_rt, WS_OVERLAPPEDWINDOW, FALSE);
	
	hwnd = CreateWindow(
		wndclass.lpszClassName,
		L"길찾기 프로그램",
		WS_OVERLAPPEDWINDOW,
		(Screen_Width / 2) - (Wnd_Width / 2),
		(Screen_Height / 2) - (Wnd_Height / 2),
		gWnd_rt.right - gWnd_rt.left,
		gWnd_rt.bottom - gWnd_rt.top,
		nullptr,
		nullptr,
		wndclass.hInstance,
		nullptr
	);

}

bool LB = false;
std::pair<int, int> startPos = { 0,0 };
std::pair<int, int> targetPos = { 0,0 };
std::pair<int, int> mousePos;
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) 
	{
	case WM_CREATE:
		Initalize(hWnd);
		return 0;

	case WM_PAINT:
		PaintedDraw(hWnd);
		return 0;

	case WM_SIZE:
		// Reset and resize swapchain
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_MOUSEMOVE:
		ClickPos(lParam,mousePos);
		if (LB)
		{
			std::pair<int, int> pos;
			ClickPos(lParam, pos);
			graph[pos.first][pos.second] = 3;
			DrawGrid(hWnd, pos);
		}
		break;

	case WM_LBUTTONDOWN: 
	{
		// 오른쪽 버튼 눌려져있을 때는 작동 X
		LB = true;
		std::pair<int, int> pos;
		ClickPos(lParam, pos);
		if (!IsVisited(pos))
		{
			graph[pos.first][pos.second] = 3;
			DrawGrid(hWnd, pos);
		}
		break;
	}
	case WM_LBUTTONUP:
		LB = false;
		ResetVisited();
		break;
	
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) 
		{
			ResetGraph();
			InvalidateRect(hWnd, nullptr, true);
		}
		if (wParam == VK_SPACE)
		{
			Dijkstra(hWnd);
		}
		break;
	case WM_CHAR:
		switch (wParam) 
		{
		case 's':
			graph[startPos.first][startPos.second] = 0;
			DrawGrid(hWnd, startPos);
			startPos = mousePos;
			
			graph[startPos.first][startPos.second] = 1;
			DrawGrid(hWnd, startPos);
			
			break;
		case 'a':
			graph[targetPos.first][targetPos.second] = 0;
			DrawGrid(hWnd, targetPos);
			targetPos = mousePos;
			
			graph[targetPos.first][targetPos.second] = 2;
			DrawGrid(hWnd, targetPos);
			
			break;
		}
		break;
			
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
