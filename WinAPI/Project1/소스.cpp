#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE preInstance, LPSTR lpCmdLine, int bcmdShow)
{

	WNDCLASS wndClass;
	LPCWSTR title = L"WinAPI����";


	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = title;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_VREDRAW | CS_HREDRAW;

	RegisterClass(&wndClass);

	HWND hwnd = CreateWindow(
		title, title, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 1024, 728,
		NULL, NULL, hInstance, NULL);

	if (!hwnd )
	{
		MessageBox(nullptr, L"������ ������ ��", L"�����߻�", MB_ICONERROR);
		return -1;
	}
	ShowWindow(hwnd, bcmdShow);
	UpdateWindow(hwnd);

	MSG msg;

	while (GetMessage(&msg, hwnd, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return  (int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_QUIT:
		DestroyWindow(hwnd);
		break;
	case WM_LBUTTONDOWN:
		HDC hdc = GetDC(hwnd);

		TextOut(hdc, 100, 100, L"ó���̾� �̷�����", 9);
		ReleaseDC(hwnd, hdc);
		return 0;
	}

	return DefWindowProc(hwnd, iMessage, wParam, lParam);
}