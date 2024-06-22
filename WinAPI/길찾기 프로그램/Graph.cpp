#include "stdafx.h"
#include "Graph.h"
#include <queue> //ť ���

#include <chrono>
#include <iostream>
#include <string>


using namespace std;

void Graph::Initalize(const HWND& hwnd)
{

	Row = (gWnd_rt.right - gWnd_rt.left) / BlockSize;
	Column = (gWnd_rt.bottom - gWnd_rt.top) / BlockSize;

	m_graph.resize(Row, vector<int>(Column, 0));
	m_visited.resize(Row, vector<bool>(Column, false));
}


bool Graph::IsVisited(const pair<int, int>& idx)
{
	auto [row, col] = idx;
	return m_visited[row][col];
}

bool Graph::IsWall(const std::pair<int, int>& idx)
{
	if (idx.first >= Row || idx.second >= Column)
		return false;
	
	return m_graph[idx.first][idx.second] == int(EBrush::BlackBrush);;
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
void Graph::DrawGrid(const HWND& hwnd, const std::pair<int, int>& idx, EBrush color)
{
	m_graph[idx.first][idx.second] = int(color);
	m_visited[idx.first][idx.second] = true;
	DrawModule::DrawGrid(hwnd, idx, color);
}

void Graph::PaintedDraw(const HWND& hwnd)
{
	PAINTSTRUCT pt;
	HDC hdc = BeginPaint(hwnd, &pt);

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Column; j++)
		{
			DrawGrid(hwnd, { i,j }, EBrush(m_graph[i][j]));
		}
	}
	EndPaint(hwnd,&pt);
}
void Graph::MouseLB(const HWND& hwnd, const std::pair<int, int>& idx, EBrush color)
{
	// �̹� �湮 �ߴٸ� ����
	if (IsVisited(idx))
		return;
	if (ChkColor(idx, color)) 
	{
		DrawGrid(hwnd, idx, EBrush::WhiteBrush);
		return;
	}
	DrawGrid(hwnd, idx, color);
}

void Graph::SelectStart(const HWND& hwnd, const pair<int, int>& idx)
{
	DrawGrid(hwnd, m_startPos, EBrush::WhiteBrush);
	m_startPos = idx;
	DrawGrid(hwnd, m_startPos, EBrush::GreenBrush);
}

void Graph::SelectEnd(const HWND& hwnd, const pair<int, int>& idx)
{
	DrawGrid(hwnd, m_targetPos, EBrush::WhiteBrush);
	m_targetPos = idx;
	DrawGrid(hwnd, m_targetPos, EBrush::RedBrush);
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
			if (visited[rx][ry] || m_graph[rx][ry] == int(EBrush::BlackBrush))
				continue;
			//�밢���� ��쿡
			
			switch (i)
			{
			case 4:
				if(IsWall({ rx + 1,ry }) && IsWall({ rx ,ry + 1 }))
					continue;
				break;
			case 5:
				if (IsWall({ rx + 1,ry }) && IsWall({ rx ,ry - 1 }))
					continue;
				break;
			case 6:
				if (IsWall({ rx ,ry - 1 }) && IsWall({ rx ,ry + 1 }))
					continue;
				break;
			case 7:
				if (IsWall({ rx - 1,ry }) && IsWall({ rx ,ry - 1 }))
					continue;
				break;

			}
	
			if (m_graph[rx][ry] == int(EBrush::RedBrush))
			{
				for (auto& current : route)
				{
					
					m_graph[current.first][current.second] = int(EBrush::OrangeBrush);
					DrawGrid(hwnd, { current.first,current.second },EBrush::OrangeBrush);
					Sleep(5);
				}
				goto search;
			}
			visited[rx][ry] = true;
			vector<pair<int, int>> lroute = route;
			lroute.push_back({ rx,ry });

			q.push({ {rx,ry} , lroute });
			
			m_graph[rx][ry] = int(EBrush::GrayBrush);
			DrawGrid(hwnd, { rx,ry },EBrush::GrayBrush);
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
/* 
	���� ���� - ��ǥ���� ������ �Ÿ��� ����.
	�밢���� 1.4 = ��Ʈ 2�� ��� ��.

*/
void Graph::AStar(const HWND& hwnd)
{
	
}
