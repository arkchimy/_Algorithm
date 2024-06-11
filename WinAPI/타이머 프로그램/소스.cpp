#include <windows.h>
#include <time.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	time_t myTimer = 0;
	static WCHAR str[30];
	static HANDLE timer;
	PAINTSTRUCT ps;
	RECT rt = {100,100,500,200};
	HDC hdc;
	static size_t convertedChars = 0;
		switch (iMessage)
	{
		case WM_CREATE:
			timer = (HANDLE)SetTimer(hwnd, 1, 1000, nullptr);
			break;
		case WM_TIMER:

			time(&myTimer);
			char mbstr[30];
			// ctime_s 사용
			ctime_s(mbstr, sizeof(mbstr), &myTimer);
			mbstowcs_s(&convertedChars, str, mbstr, _TRUNCATE);
			InvalidateRect(hwnd, &rt, true);  // Rect를 지정하여 특정 부분만 다시 그리게 함 => 깜빡임 최소화
			return 0;

		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			DrawText(hdc, (LPCWSTR)str, convertedChars - 1,&rt, DT_CENTER);
			EndPaint(hwnd, &ps);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			KillTimer(hwnd, 1);
			break;
	}
	return DefWindowProc(hwnd, iMessage, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPreInstance , LPSTR s, int nCmdShow)
{

	LPCWSTR title = L"타이머 프로그램";

	WNDCLASS wndclass;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = nullptr;
	wndclass.lpszClassName = title;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hIcon = LoadIcon(nullptr,IDI_APPLICATION);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndclass);

	HWND hwnd = CreateWindow(title, title, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, nullptr, nullptr, nullptr, nullptr);

	if (hwnd == nullptr)
		MessageBox(hwnd, L"윈도우 생성 실패", L"윈도우 생성 에러", MB_ICONERROR);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	MSG msg;

	while (GetMessage(&msg, hwnd, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return int(msg.wParam);

}