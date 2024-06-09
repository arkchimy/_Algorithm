#include <windows.h>

#define Width 1024	
#define Height 728
#define Device_Width 2560
#define Device_Height 1080

const float aspect = float(Width) / Height;
LPCWSTR title = L"첫번째 API";

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR a, int ncmdShow)
{
	WNDCLASS wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = title;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;

	RegisterClass(&wndclass);
	
	HWND hwnd = CreateWindow(
		title, title, WS_OVERLAPPEDWINDOW | WS_VSCROLL,
		Device_Width/2 - Width/2, Device_Height / 2 - Height / 2,Width,Height,
		NULL, NULL,hInstance, NULL
		);

	MSG msg;
	if (!hwnd) 
	{
		MessageBox(nullptr, L"윈도우 생성 실패", L"윈도우 생성 실패", MB_ICONERROR);
		
		return -1;
	}
	else
	{
		ShowWindow(hwnd, ncmdShow);
		UpdateWindow(hwnd);

		

		while (GetMessage(&msg, 0, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		}
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	static WCHAR str[256];
	static int len = 0;

	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		MessageBeep(MB_OK);
		return 0;
	case WM_CHAR:
		str[len++] = TCHAR(wParam);
		str[len] = 0;
		InvalidateRect(hwnd, nullptr, false);
		return 0;
		
	case WM_PAINT:
		PAINTSTRUCT ps;
		RECT rt = { 100,100,500,500 };
		HDC hdc = BeginPaint(hwnd, &ps);
		DrawText(hdc, str,len + 1, &rt, 0);
		EndPaint(hwnd, &ps);

		return 0;
	}
	return DefWindowProc(hwnd, iMessage, wParam, lParam);
}