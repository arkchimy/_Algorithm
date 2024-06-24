#include "stdafx.h"
#include "Graph.h"
#include <queue> //ť ���

#include <chrono>
#include <iostream>
#include <string>

using namespace std;

void TextureCoordinate(const pair<int, int>& idx, pair<int, int>& rt)
{
	rt = { idx.second,idx.first };
}
void ArrayCoordinate(const pair<int, int>& idx, pair<int, int>& rt)
{
	rt = { idx.second,idx.first };
}

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

bool Graph::IsWall(const std::pair<int, int>& idx) // array
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
	m_graph[idx.second][idx.first] = int(color);
	DrawModule::DrawGrid(hwnd, idx, color);
}

void Graph::TextGrid(const HWND& hwnd, const std::pair<int, int>& idx,LPCWSTR str)
{
	HDC hdc = GetDC(hwnd);
	RECT rt = {
		BlockSize * idx.first,
		BlockSize * idx.second,
		BlockSize * idx.first + BlockSize,
		BlockSize * idx.second + BlockSize
	};

	DrawText(hdc, str,3,&rt, DT_CENTER | DT_VCENTER);
	ReleaseDC(hwnd,hdc);

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
	pair<int, int> array_idx;
	ArrayCoordinate(idx, array_idx);
	// �̹� �湮 �ߴٸ� ����
	if (IsVisited(array_idx))
		return;
	if (ChkColor(array_idx, color))
	{
		m_visited[array_idx.first][array_idx.second] = true;
		DrawGrid(hwnd, idx, EBrush::WhiteBrush);
		return;
	}
	m_visited[array_idx.first][array_idx.second] = true;
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
	swprintf(buffer, 32, L"%lf �ð��� �ҿ�Ǿ����ϴ�.", number);
	string str = to_string((chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3));
	MessageBox(hwnd, buffer, L"���ͽ�Ʈ�� �ҿ�ð�", MB_OK);

}
/* 
	���� ���� - ��ǥ���� ������ �Ÿ��� ����.
	�밢���� 1.4 = ��Ʈ 2�� ��� ��.

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
		pair<int, int> texturecoordinate_idx;
		TextureCoordinate({ rx,ry }, texturecoordinate_idx);

		if (texturecoordinate_idx.first == m_targetPos.first && 
			texturecoordinate_idx.second == m_targetPos.second)
		{
			if(i < 4)
				node = Node(texturecoordinate_idx, m_targetPos, preNode.currentCost + 10);
			else
				node = Node(texturecoordinate_idx, m_targetPos, preNode.currentCost + 14);
			q.emplace(node);

			break;
		}
		if (rx < 0 || ry < 0 || Row <= rx || Column <= ry)
			continue;
		if (m_visited[rx][ry] || IsWall({ rx,ry }))
			continue;

		DrawGrid(hwnd, texturecoordinate_idx, EBrush::GreenBrush);
		//�밢���� ��쿡
		// is Wall �� arrayidx
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
			node = Node(texturecoordinate_idx, m_targetPos, preNode.currentCost + 10);
			q.emplace(node);
			// int�� LPCWSTR ���ڿ��� ��ȯ
			wchar_t buffer[20];
			swprintf_s(buffer, sizeof(buffer) / sizeof(wchar_t), L"%d", node.total);
			TextGrid(hwnd, texturecoordinate_idx, buffer);
			continue;
		}
		node = Node(texturecoordinate_idx, m_targetPos, preNode.currentCost + 14);
		q.emplace(node);

		wchar_t buffer[20];
		swprintf_s(buffer, sizeof(buffer) / sizeof(wchar_t), L"%d", node.total);
		TextGrid(hwnd, texturecoordinate_idx, buffer);

		
	}
	
}


void Graph::AStar(const HWND& hwnd)
{
	ResetVisited();
	auto sTime = chrono::high_resolution_clock::now();

	pair<int, int> array_idx;
	ArrayCoordinate(m_startPos, array_idx); //  m_startPos �� texturecoordinate ��
	priority_queue<Node,vector<Node>> q; // Node���� texturecoordinate�� �Է�

	Node node = Node(m_startPos.first, m_startPos.second, m_targetPos, 0);
	q.push(node);

	m_visited[array_idx.first][array_idx.second] = true; //  ���
	AStarDistance(hwnd,q, array_idx);
	
	while (!q.empty())
	{
		auto current = q.top();
		q.pop();

		pair<int, int> array_idx;
		ArrayCoordinate(current.idx, array_idx);

		auto& [x, y] = array_idx;
		//m_visited[x][y] = true;

		if (y == m_targetPos.first && x == m_targetPos.second)
		{
			break;
		}

		DrawGrid(hwnd, { y, x }, EBrush::OrangeBrush);
		q.push(current);
		AStarDistance(hwnd,q, {x,y});
	}
	double number = (chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3);
	wchar_t buffer[32];
	swprintf(buffer, 32, L"%lf �ð��� �ҿ�Ǿ����ϴ�.", number);
	string str = to_string((chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3));
	MessageBox(hwnd, buffer, L"AStart �ҿ�ð�", MB_OK);
	ResetVisited();
}
