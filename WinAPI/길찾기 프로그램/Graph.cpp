#include "stdafx.h"
#include "Graph.h"
#include <queue> //큐 사용
#include <chrono>
#include <iostream>
#include <string>

int Row;
int Column;

using namespace std;

std::vector<std::vector<int>> graph;
std::vector<std::vector<bool>> visited;

HBRUSH BlackBrush;
HBRUSH GreenBrush;
HBRUSH RedBrush;
HBRUSH WhiteBrush;
HBRUSH GrayBrush;
void DrawGrid(const HWND& hwnd, const pair<int, int>& idx)
{
	HDC hdc = GetDC(hwnd);
	visited[idx.first][idx.second] = true;

	switch (graph[idx.first][idx.second])
	{
		case 0:
			SelectObject(hdc, WhiteBrush);
			break;
		case 1:
			SelectObject(hdc, GreenBrush);
			break;
		case 2:
			SelectObject(hdc, RedBrush);
			break;
		case 3:
			SelectObject(hdc, BlackBrush);
			break;
		default:
			SelectObject(hdc, GrayBrush);

	}

	Rectangle(hdc,
		BlockSize * idx.first,
		BlockSize * idx.second,
		BlockSize * idx.first + BlockSize,
		BlockSize * idx.second + BlockSize);
	ReleaseDC(hwnd, hdc);
}

bool IsVisited(const pair<int, int>& idx)
{
	auto [row, col] = idx;
	return visited[row][col];
}

void ClickPos(LPARAM lParam, std::pair<int, int>& pos)
{
	int x = (int)LOWORD(lParam) / BlockSize;
	int y = (int)HIWORD(lParam) / BlockSize;
	pos = { x,y };
}

void ResetVisited()
{
	for (std::vector<bool>& row : visited)
		fill(row.begin(), row.end(), false);
}
void ResetGraph()
{
	for (std::vector<int>& row : graph)
		fill(row.begin(), row.end(), 0);
}
void Initalize(const HWND& hwnd)
{
	GreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	RedBrush = CreateSolidBrush(RGB(255, 0, 0));
	BlackBrush = CreateSolidBrush(RGB(0, 0, 0));
	WhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
	GrayBrush = CreateSolidBrush(RGB(125, 125, 125));

	Row = (gWnd_rt.right - gWnd_rt.left) / BlockSize;
	Column = (gWnd_rt.bottom - gWnd_rt.top) / BlockSize;

	graph.resize( Row, vector<int>(Column, 0));
	visited.resize( Row, vector<bool>(Column, false));
}

void PaintedDraw(const HWND& hwnd)
{
	PAINTSTRUCT pt;
	HDC hdc = BeginPaint(hwnd, &pt);

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			RECT rt =
			{
				BlockSize * i,
				BlockSize * j,
				BlockSize * i + BlockSize,
				BlockSize * j + BlockSize
			};

			switch (graph[i][j])
			{
			case 0:
				SelectObject(hdc, WhiteBrush);
				break;
			case 1:
				SelectObject(hdc, GreenBrush);
				break;
			case 2:
				SelectObject(hdc, RedBrush);
				break;
			default:
				SelectObject(hdc, GrayBrush);
			}
			Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
		}
	}
	EndPaint(hwnd,&pt);
}
void Dijkstra(const HWND& hwnd)
{
	int dx[] = { -1, 1,0,0 };
	int dy[] = { 0, 0,-1,1 };

	vector<vector<bool>> visited(Row,vector<bool>(Column,false));
	
	queue<pair<int, int>> q;
	q.push(startPos );
	visited[startPos.first][startPos.second] = true;
	auto sTime = chrono::high_resolution_clock::now();

	while (!q.empty())
	{
		auto [x,y] = q.front();
		q.pop();

		int rx, ry;
		
		for (int i = 0; i < 4; i++)
		{
			rx = x + dx[i];
			ry = y + dy[i];

			if (rx < 0 || ry < 0 || Row <= rx || Column <= ry)
				continue;
			if (visited[rx][ry] || graph[rx][ry] == 3)
				continue;
		
			if (graph[rx][ry] == 2)
				goto search;
			visited[rx][ry] = true;
			q.push({ rx,ry });
			
			
			graph[rx][ry] = 10;
			DrawGrid(hwnd, { rx,ry });
			Sleep(5);
		}
		
	}
search:
	double number = (chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3);
	wchar_t buffer[32];
	swprintf(buffer, 32, L"%lf 시간이 소요되었습니다.", number);
	string str = to_string((chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3));
	MessageBox(hwnd, buffer, L"다익스트라 소요시간", MB_OK);

}