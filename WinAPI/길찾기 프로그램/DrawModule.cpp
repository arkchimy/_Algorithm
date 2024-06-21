#include "stdafx.h"
#include "DrawModule.h"


// WhiteFill  ��� ���� DC�� Draw�ϸ� �� �Ͱ�����
// WM_Paint ������ �ٽ� �׸� ��� ���� ���� �ʿ���.
// ������ �ش� �ε��� ���� ���� �����Ͽ� ���� ����

using namespace std;

std::vector<std::vector<int> > gGraph;
std::vector<std::vector<bool>> gVisited;

void DrawModule::DrawGrid(const HWND& hwnd, const std::pair<int, int>& idx, EBrush color)
{
	//static  ������ DrawGrid ���� ���������ν� ���ټ� ���� - ���������� ������ ����
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
