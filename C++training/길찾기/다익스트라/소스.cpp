#include <windows.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <cmath>

#define Wnd_Width  800
#define Wnd_Height 800
#define Screen_Width 2560
#define Screen_Height 1080
#define Block_Size 20
/*

*/
using namespace std;

vector<vector<int>> graph;
vector<int> d;
HBRUSH GreenBrush;
HBRUSH RedBrush;
HBRUSH BlackBrush;
HBRUSH WhiteBrush;

void DrawGraph(HDC& hdc);
void dijkstra(const int& start)
{
	queue<pair<int,int>> q;
	q.push({ start,0 });

	while (!q.empty())
	{
		auto [front,cost] = q.front();
		q.pop();
		for (const int& idx : graph[front])
		{
			if (d[idx] < cost + 1)
				continue;
			d[idx] = cost + 1;
			q.push({idx,cost + 1});
		}
		
	}
}

void LClickEvent(HDC& hdc, WORD& x, WORD& y)
{
	float row = x / Block_Size;
	float column = y / Block_Size ;

	x = (WORD)round(row);
	y = (WORD)round(column);
	if(graph[x][y] < 2)
		graph[x][y]++;
}
void RClickEvent(HDC& hdc, WORD& x, WORD& y)
{
	float row = x / Block_Size;
	float column = y / Block_Size;

	x = (WORD)round(row);
	y = (WORD)round(column);
	if(graph[x][y] != -1)
		graph[x][y]--;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	static bool LB = false, RB = false;

	RECT rt = {100,100,500,500};
	PAINTSTRUCT pt;
	HDC hdc;
	WORD x;
	WORD y;
	switch (iMessage)
	{
	case WM_CREATE:
		hdc = BeginPaint(hwnd, &pt);
		DrawGraph(hdc);
		EndPaint(hwnd, &pt);
		return 0;

	case WM_LBUTTONDOWN:
		LB = true;
		return 0;
	case WM_RBUTTONDOWN:
		RB = true;
		return 0;
	case WM_LBUTTONUP:
		LB = false;
		return 0;
	case WM_RBUTTONUP:
		RB = false;
		return 0;
	case WM_MOUSEMOVE:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		if (LB) 
		{
			LClickEvent(hdc, x, y);
		}
		if (RB)
		{
			RClickEvent(hdc, x, y);
		}
		rt = 
		{
			Block_Size * x,
			Block_Size * y,
			Block_Size * x + Block_Size,
			Block_Size * y + Block_Size
		};

		InvalidateRect(hwnd, &rt, true);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &pt);
		DrawGraph(hdc);
		EndPaint(hwnd, &pt);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, iMessage, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR t, int nCmdShow)
{
	LPCWSTR title = L"다익스트라 프로그램";

	graph.resize(Wnd_Width / Block_Size,vector<int>(Wnd_Width / Block_Size,0));

	GreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	RedBrush = CreateSolidBrush(RGB(255, 0, 0));
	BlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	WhiteBrush = CreateSolidBrush(RGB(255, 255, 255));

	WNDCLASS wndclass;

	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;

	wndclass.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	wndclass.lpszMenuName = title;
	wndclass.lpszClassName = title;
	
	wndclass.style = CS_VREDRAW | CS_HREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;

	RegisterClass(&wndclass);
	
	HWND hwnd = CreateWindow(title,
		title,
		WS_OVERLAPPEDWINDOW,
		(Screen_Width / 2) - (Wnd_Width / 2),
		(Screen_Height / 2) - (Wnd_Width / 2),
		Wnd_Width,
		Wnd_Height,
		nullptr,
		nullptr,
		hInstance,
		nullptr
	);

	if (hwnd == nullptr)
	{
		MessageBox(nullptr, L"윈도우 생성 실패", L"에러", MB_ICONERROR);
		return -1;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;


}

void DrawGraph(HDC& hdc)
{
	for(int i =0; i < Wnd_Width/ Block_Size; i++)
		for (int j = 0; j < Wnd_Height / Block_Size; j++) 
		{
			if(graph[i][j] == 1)
				SelectObject(hdc, GreenBrush);
			else if(graph[i][j] == 2)
				SelectObject(hdc, RedBrush);
			else if(graph[i][j] == -1)
				SelectObject(hdc, BlackBrush);
			else
				SelectObject(hdc, WhiteBrush);
			Rectangle(hdc,
				0 + Block_Size * i,
				0 + Block_Size * j,
				0 + Block_Size * i + Block_Size,
				0 + Block_Size * j + Block_Size);
		}
}