#include "stdafx.h"
#include "WndAPI.h"
#include <iostream>

using namespace std;

int main()
{
	Arkchimy_Wnd wnd;

	ShowWindow(Arkchimy_Wnd::hwnd, SW_SHOWDEFAULT);
	UpdateWindow(Arkchimy_Wnd::hwnd);

	if (Arkchimy_Wnd::hwnd == nullptr)
		MessageBox(0, L"������ ��������", L"���� �߻�", MB_ICONERROR);
	MSG msg;

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}