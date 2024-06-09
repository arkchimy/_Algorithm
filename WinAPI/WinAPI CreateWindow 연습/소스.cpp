#include <windows.h>
#define Width 1024
#define Height 728

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM  wParam, LPARAM lParam)
{
	switch(iMessage) 
	{
		case WM_QUIT:
			DestroyWindow(hWnd);
			break;
		case WM_LBUTTONDOWN:
			HDC hdc = GetDC(hWnd);
			TextOut(hdc, 100, 100, L"태어나서 처음이야", 9);
			ReleaseDC(hWnd, hdc);
			return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS Wndclass;
	LPCWSTR title = L"타이틀 제목";

	Wndclass.cbClsExtra = 0;
	Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.lpszClassName = title;
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpszMenuName = NULL;


	RegisterClass(&Wndclass);


	HWND hWnd =
	CreateWindow(
		title, title, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, Width, Height,
		NULL, NULL, hInstance, NULL
	);

	
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	if (!hWnd) 
	{
		MessageBox(NULL, L"윈도우 생성 실패!", L"오류", MB_ICONEXCLAMATION | MB_OK);
		return 1;
	}
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

}