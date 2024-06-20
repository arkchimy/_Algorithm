#pragma once

void Initalize(const HWND& hwnd);
void PaintedDraw(const HWND& hwnd);
void DrawGrid(const HWND& hwnd,const std::pair<int,int>& idx); // GetDC를 이용한 Draw
bool IsVisited(const std::pair<int, int>& idx); //  마우스 꾹 눌렀을 때 연속클릭 안되게하는 방지
void ClickPos(LPARAM lParam, std::pair<int, int>& pos);
void ResetVisited();
void ResetGraph();
void Dijkstra(const HWND& hwnd);

extern std::vector<std::vector<int>> graph;
extern std::vector<std::vector<bool>> visited;
