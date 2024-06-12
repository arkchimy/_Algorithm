#include <windows.h>

#define wnd_Widtch 1024
#define wnd_height 728

#define Screen_Width 2560
#define Screen_Height 1080


void CALLBACK TimerProc(HWND hwnd, UINT uMessage, UINT id, DWORD d)
{

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	static HANDLE timer;
	switch (uMessage)
	{
	case WM_CREATE:
		SetTimer(hwnd, 1, 100, TimerProc);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		SendMessage(hwnd, WM_TIMER, 1, 0);
		return 0;
	case WM_TIMER:
		switch (wParam)
		{
		case 1:
			HDC hdc = GetDC(hwnd);
			TextOut(hdc, 100, 100, L"테스트", 3);
			return 0;
		}
	}

	return DefWindowProc(hwnd, uMessage, wParam, lParam);

}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR d, int nCmdShow)
{

	LPCWSTR title = L"콜백 테스트 프로그램";

	WNDCLASS wndclass;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndclass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);

	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = nullptr;
	wndclass.lpszClassName = title;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.style = CS_VREDRAW | CS_HREDRAW;
	
	RegisterClass(&wndclass);

	HWND hwnd = CreateWindow(title, title, WS_OVERLAPPEDWINDOW,
		(Screen_Width / 2) - (wnd_Widtch / 2), (Screen_Height / 2) - (wnd_height / 2)
		, wnd_Widtch, wnd_height, nullptr, nullptr, hInstance, nullptr
	);
	if (hwnd == nullptr) 
	{
		MessageBox(nullptr, L"윈도우 생성실패", L"에러 발생", MB_ICONERROR);
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

	return int(msg.wParam);

}