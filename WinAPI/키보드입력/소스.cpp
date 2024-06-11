#include <windows.h>


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	static WCHAR str[256];
	static int len = 0;
	str[len] = 0;
	
	switch(iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CHAR:
		str[len] = WCHAR(wParam);
		str[len + 1] = 0;
		len++;
		InvalidateRect(hwnd, nullptr, false);
		return 0;
	case WM_PAINT:
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, str, len);
		EndPaint(hwnd, &ps);
		
		return 0;

	}
	return DefWindowProc(hwnd, iMessage, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR nd, int cmdShow)
{
	WNDCLASS wndclass;

	const LPCWSTR title = L"키보드 입력 프로그램";

	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndclass.lpszMenuName = nullptr;
	wndclass.lpszClassName = title;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.style = CS_VREDRAW | CS_HREDRAW;
	
	RegisterClass(&wndclass);
	HWND hwnd = CreateWindow(title, title, WS_OVERLAPPEDWINDOW
		, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 728, NULL, NULL, NULL, NULL
	);


	if (hwnd == nullptr)
	{
		MessageBox(hwnd, L"윈도우 생성 실패", L"생성 에러", MB_ICONERROR);
		return -1;
	}
	ShowWindow(hwnd, cmdShow);
	UpdateWindow(hwnd);

	MSG msg;
	
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return int(msg.wParam);
}