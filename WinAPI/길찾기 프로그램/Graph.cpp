#include "stdafx.h"
#include "Graph.h"
#include <queue> //ť ���
#include <chrono>
#include <iostream>
#include <string>

int Row;
int Column;

using namespace std;

void Graph::WhiteFill(const pair<int, int>& node)
{
	m_graph[node.first][node.second] = 0;
}
void Graph::GreenFill(const pair<int, int>& node)
{
	m_graph[node.first][node.second] = 1;
}
void Graph::RedFill(const pair<int, int>& node)
{
	m_graph[node.first][node.second] = 2;
}
void Graph::BlackFill(const pair<int, int>& node)
{
	m_graph[node.first][node.second] = 3;
}
void Graph::OrangeFill(const pair<int, int>& node)
{
	m_graph[node.first][node.second] = 10;
}


void Graph::DrawGrid(const HWND& hwnd, const pair<int, int>& idx)
{
	HDC hdc = GetDC(hwnd);
	m_visited[idx.first][idx.second] = true;

	switch (m_graph[idx.first][idx.second])
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
		case 10:
			SelectObject(hdc, OrangeBrush);
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

bool Graph::IsVisited(const pair<int, int>& idx)
{
	auto [row, col] = idx;
	return m_visited[row][col];
}

void Graph::ClickPos(LPARAM lParam, std::pair<int, int>& pos)
{
	int x = (int)LOWORD(lParam) / BlockSize;
	int y = (int)HIWORD(lParam) / BlockSize;
	pos = { x,y };
}

void Graph::ResetVisited()
{
	for (std::vector<bool>& row : m_visited)
		fill(row.begin(), row.end(), false);
}
void Graph::ResetGraph()
{
	for (std::vector<int>& row : m_graph)
		fill(row.begin(), row.end(), 0);
}
void Graph::Initalize(const HWND& hwnd)
{


	Row = (gWnd_rt.right - gWnd_rt.left) / BlockSize;
	Column = (gWnd_rt.bottom - gWnd_rt.top) / BlockSize;

	m_graph.resize( Row, vector<int>(Column, 0));
	m_visited.resize( Row, vector<bool>(Column, false));
}

void Graph::PaintedDraw(const HWND& hwnd)
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

			switch (m_graph[i][j])
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
void Graph::Dijkstra(const HWND& hwnd)
{
	int dx[] = { -1, 1,0,0 ,-1,1,-1,1};
	int dy[] = { 0, 0,-1,1 ,-1,-1,1,1};

	vector<vector<bool>> visited(Row,vector<bool>(Column,false));
	
	queue<pair < pair<int, int>,vector<pair<int,int> > >> q;
	q.push({ m_startPos,vector<pair<int,int>>() });

	visited[m_startPos.first][m_startPos.second] = true;
	auto sTime = chrono::high_resolution_clock::now();


	while (!q.empty())
	{
		auto [pos,route] = q.front();
		q.pop();

		int rx, ry;
		
		for (int i = 0; i < 8; i++)
		{
			rx = pos.first + dx[i];
			ry = pos.second + dy[i];

			if (rx < 0 || ry < 0 || Row <= rx || Column <= ry)
				continue;
			if (visited[rx][ry] || m_graph[rx][ry] == 3)
				continue;
		
			if (m_graph[rx][ry] == 2) 
			{
				for (auto& current : route)
				{
					m_graph[current.first][current.second] = 10;
					DrawGrid(hwnd, { current.first,current.second });
					Sleep(5);
				}
				goto search;
			}
			visited[rx][ry] = true;
			vector<pair<int, int>> lroute = route;
			lroute.push_back({ rx,ry });

			q.push({ {rx,ry} , lroute });
			
			m_graph[rx][ry] = 9;
			DrawGrid(hwnd, { rx,ry });
			Sleep(5);
		}
		
	}
search:
	double number = (chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3);
	wchar_t buffer[32];
	swprintf(buffer, 32, L"%lf �ð��� �ҿ�Ǿ����ϴ�.", number);
	string str = to_string((chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3));
	MessageBox(hwnd, buffer, L"���ͽ�Ʈ�� �ҿ�ð�", MB_OK);

}