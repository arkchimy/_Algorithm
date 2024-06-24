#pragma once
#define BRUSH_CNT 7


class DrawModule
{
public:
	virtual void DrawGrid(const HWND& hwnd, const std::pair<int, int>& idx , EBrush color = EBrush::WhiteBrush); // GetDC를 이용한 Draw
	
};

