#pragma once
#define BRUSH_CNT 6


class DrawModule
{
public:
	void DrawGrid(const HWND& hwnd, const std::pair<int, int>& idx , EBrush color = EBrush::WhiteBrush); // GetDC를 이용한 Draw
	
protected:
	
};

