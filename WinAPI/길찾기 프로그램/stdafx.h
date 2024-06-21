#pragma once
#include <windows.h>
#include <vector>

#define BlockSize 20

extern int Screen_Width;
extern int Screen_Height;
extern int Wnd_Width;
extern int Wnd_Height;

extern RECT gWnd_rt; // ���� ���̴� �������� ũ��

enum class EBrush
{
	WhiteBrush = 0,
	GreenBrush,
	RedBrush,
	BlackBrush,
	GrayBrush,
	OrangeBrush,

};
