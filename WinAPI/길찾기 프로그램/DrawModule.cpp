#include "stdafx.h"
#include "DrawModule.h"


// WhiteFill  즉시 색을 DC로 Draw하면 될 것같지만
// WM_Paint 때문에 다시 그릴 경우 저장 값이 필요함.
// 때문에 해당 인덱스 값에 값을 저장하여 색을 보존

using namespace std;

std::vector<std::vector<int> > gGraph;
std::vector<std::vector<bool>> gVisited;

void DrawModule::DrawGrid(const HWND& hwnd, const std::pair<int, int>& idx, EBrush color)
{
	//static  변수를 DrawGrid 내에 삽입함으로써 접근성 제어 - 전역변수의 단점을 지움
	static HBRUSH mBrush[BRUSH_CNT] = 
	{
		CreateSolidBrush(RGB(255, 255, 255)),
		CreateSolidBrush(RGB(0, 255, 0)),
		CreateSolidBrush(RGB(255, 0, 0)),
		CreateSolidBrush(RGB(0, 0, 0)),
		CreateSolidBrush(RGB(125, 125, 125)),
		CreateSolidBrush(RGB(255, 127, 0))
	};

	HDC hdc = GetDC(hwnd);
	SelectObject(hdc, mBrush[int(color)]);
	
	Rectangle(hdc,
		BlockSize * idx.first,
		BlockSize * idx.second,
		BlockSize * idx.first + BlockSize,
		BlockSize * idx.second + BlockSize);
	ReleaseDC(hwnd, hdc);

}
