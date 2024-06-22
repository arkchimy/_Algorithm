#include "stdafx.h"
#include <iostream>
#include "Graph.h"


using namespace std;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int Screen_Width = 2580;
int Screen_Height = 1080;
int Wnd_Width = 600;
int Wnd_Height = 600;

bool LB = false;

std::pair<int, int> mousePos;

RECT gWnd_rt;

Graph graph;

void InitWindow(HWND & hwnd)
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
int main()
{
	HWND hwnd;
	InitWindow(hwnd);

	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);

	if (hwnd == nullptr)
		MessageBox(0, L"윈도우 생성실패", L"에러 발생", MB_ICONERROR);
	MSG msg;

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

void ClickPos(LPARAM lParam, std::pair<int, int>& pos)
{
	int x = (int)LOWORD(lParam) / BlockSize;
	int y = (int)HIWORD(lParam) / BlockSize;
	pos = { x,y };
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		graph.Initalize(hWnd);
		return 0;

	case WM_PAINT:
		graph.PaintedDraw(hWnd);
		return 0;

	case WM_SIZE:
		// Reset and resize swapchain
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_MOUSEMOVE:
		ClickPos(lParam, mousePos);
		
		if (LB)
		{
			graph.MouseLB(hWnd, mousePos, EBrush::BlackBrush);
		}
		break;

	case WM_LBUTTONDOWN:
	{
		LB = true;
		graph.MouseLB(hWnd, mousePos, EBrush::BlackBrush);
		break;
	}
	case WM_LBUTTONUP:
		LB = false;
		graph.ResetVisited();
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			graph.ResetGraph();
			InvalidateRect(hWnd, nullptr, true);
		}
		if (wParam == VK_SPACE)
		{
			//graph.Dijkstra(hWnd);
			graph.AStar(hWnd);
		}
		break;
	case WM_CHAR:
		switch (wParam)
		{
		case 's':
			graph.SelectStart(hWnd, mousePos);
			break;
		case 'a':
			graph.SelectEnd(hWnd, mousePos);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}

