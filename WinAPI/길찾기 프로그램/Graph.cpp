#include "stdafx.h"
#include "Graph.h"
#include <queue> //큐 사용

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
	if ((0 <= idx.first && idx.first < Row) && (0 <= idx.second && idx.second < Column))
		return m_graph[idx.first][idx.second] == int(EBrush::BlackBrush);
	return false;
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
	// 이미 방문 했다면 리턴
	if (IsVisited(idx))
		return;
	if (ChkColor(idx, color)) 
	{
		m_visited[idx.first][idx.second] = true;
		DrawGrid(hwnd, idx, EBrush::WhiteBrush);
		return;
	}
	m_visited[idx.first][idx.second] = true;
	DrawGrid(hwnd, idx, color);
}

void Graph::SelectStart(const HWND& hwnd, const pair<int, int>& idx)
{
	DrawGrid(hwnd, m_startPos, EBrush::WhiteBrush);
	m_startPos = idx;
	DrawGrid(hwnd, m_startPos, EBrush::BlueBrush);
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
			//대각선의 경우에
			
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
					
				}
				goto search;
			}
			visited[rx][ry] = true;
			vector<pair<int, int>> lroute = route;
			lroute.push_back({ rx,ry });

			q.push({ {rx,ry} , lroute });
			
			m_graph[rx][ry] = int(EBrush::GrayBrush);
			m_visited[rx][ry] = true;
			DrawGrid(hwnd, { rx,ry },EBrush::GrayBrush);
			
		}
		
	}
search:
	double number = (chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3);
	wchar_t buffer[32];
	swprintf(buffer, 32, L"%lf 시간이 소요되었습니다.", number);
	string str = to_string((chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3));
	MessageBox(hwnd, buffer, L"다익스트라 소요시간", MB_OK);

}
/* 
	시작 지점 - 목표지점 까지의 거리를 측정.
	대각선은 1.4 = 루트 2로 취급 함.

*/



void Graph::AStarDistance(const HWND& hwnd,priority_queue<Node, vector<Node>>& q, const std::pair<int, int>& pos)
{
	int dx[] = { -1,1,0,0,-1,-1,1,1 };
	int dy[] = { 0,0,-1,1,-1,1,-1,1 };
	
	if (q.empty())
		return;
	
	Node preNode = q.top();
	q.pop();
	Node node;

	auto& [x, y] = pos;
	for (int i = 0; i < 8; i++)
	{
		int rx = x + dx[i];
		int ry = y + dy[i];
		if (rx == m_targetPos.first && ry == m_targetPos.second)
		{
			if(i < 4)
				node = Node(rx, ry, m_targetPos, preNode.currentCost + 10);
			else
				node = Node(rx, ry, m_targetPos, preNode.currentCost + 14);
			q.emplace(node);

			break;
		}
		if (rx < 0 || ry < 0 || Row <= rx || Column <= ry)
			continue;
		if (m_visited[rx][ry] || IsWall({ rx,ry }))
			continue;
		DrawGrid(hwnd, { rx, ry }, EBrush::GreenBrush);
		//대각선의 경우에
		switch (i)
		{
		case 4:
			if (IsWall({ rx + 1,ry }) && IsWall({ rx ,ry + 1 }))
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
		default:
			node = Node(rx, ry, m_targetPos, preNode.currentCost + 10);
			q.emplace(node);
			continue;
		}
		node = Node(rx, ry, m_targetPos, preNode.currentCost + 14);
		q.emplace(node);
	}
	
}

void Graph::AStar(const HWND& hwnd)
{
	ResetVisited();
	auto sTime = chrono::high_resolution_clock::now();

	pair<int, int> current = m_startPos;
	priority_queue<Node,vector<Node>> q;
	Node node = Node(current.first, current.second, m_targetPos, 0);
	q.push(node);
	m_visited[current.first][current.second] = true;
	AStarDistance(hwnd,q,current);
	
	while (!q.empty())
	{
		auto current = q.top();
		q.pop();
		auto& [x, y] = current.idx;
		m_visited[x][y] = true;
		if (x == m_targetPos.first && y == m_targetPos.second)
		{
			break;
		}
		DrawGrid(hwnd, { x, y }, EBrush::OrangeBrush);
		AStarDistance(hwnd,q, {x,y});
	}
	double number = (chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3);
	wchar_t buffer[32];
	swprintf(buffer, 32, L"%lf 시간이 소요되었습니다.", number);
	string str = to_string((chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3));
	MessageBox(hwnd, buffer, L"AStart 소요시간", MB_OK);
	ResetVisited();
}
