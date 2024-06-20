#pragma once

void Initalize(const HWND& hwnd);
void PaintedDraw(const HWND& hwnd);
void DrawGrid(const HWND& hwnd,const std::pair<int,int>& idx); // GetDC�� �̿��� Draw
bool IsVisited(const std::pair<int, int>& idx); //  ���콺 �� ������ �� ����Ŭ�� �ȵǰ��ϴ� ����
void ClickPos(LPARAM lParam, std::pair<int, int>& pos);
void ResetVisited();
void ResetGraph();
void Dijkstra(const HWND& hwnd);

extern std::vector<std::vector<int>> graph;
extern std::vector<std::vector<bool>> visited;
