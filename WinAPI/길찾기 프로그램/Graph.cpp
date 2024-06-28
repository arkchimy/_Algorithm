#include "stdafx.h"
#include "Graph.h"
#include <queue> //큐 사용

#include <chrono>
#include <iostream>
#include <string>

#include <fstream>

#define DelayTime 50
using namespace std;

void TextureCoordinate(const pair<int, int>& idx, pair<int, int>& rt)
{
	rt = { idx.second,idx.first };
}
void ArrayCoordinate(const pair<int, int>& idx, pair<int, int>& rt)
{
	rt = { idx.second,idx.first };
}

Graph::Graph()
:Row(10), Column(10)
{

}

Graph::~Graph()
{
	std::ofstream outFile("example.txt");
	std::string line;

	// 파일이 정상적으로 열렸는지 확인
	if (outFile.is_open())
	{
		for (auto& Row : m_graph) 
		{
			for (auto& Column : Row)
				outFile << Column;
			outFile << "\n";
		}
		// 파일 닫기
		outFile.close();
	}
	else 
	{
		std::cerr << "Unable to open file for reading" << std::endl;
	}
}

void Graph::Initalize(const HWND& hwnd)
{

	Row = (gWnd_rt.right - gWnd_rt.left) / BlockSize;
	Column = Row;

	m_graph.resize(Row, vector<int>(Column, 0));
	m_visited.resize(Row, vector<bool>(Column, false));

	std::ifstream inFile("example.txt");
	std::string line;
	if (inFile.is_open())
	{
		int idx = 0;
		while (std::getline(inFile, line))
		{
			
			for (char& ch : line)
			{
				if (int(ch) - '0' == 6)
					m_startPos = make_pair<int>(idx / Column,idx % Row);
				else if (int(ch) - '0' == 2)
					m_targetPos = make_pair<int>(idx / Column, idx % Row);
				m_graph[idx / Column][idx % Row] = int(ch) - '0';
				
				idx++;
			}

		}
	}
	InvalidateRect(hwnd, nullptr, true);
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
void Graph::SearchBefore()
{
	for (std::vector<int>& row : m_graph) 
	{
		for (auto& elem : row) 
		{
			if (elem == int(EBrush::RedBrush) ||
				elem == int(EBrush::BlueBrush) ||
				elem == int(EBrush::BlackBrush))
				continue;
			elem = 0;
		}
	}
}
void Graph::DrawGrid(const HWND& hwnd, const std::pair<int, int>& idx, EBrush color,float delaytime)
{
	m_graph[idx.second][idx.first] = int(color);
	DrawModule::DrawGrid(hwnd, idx, color, delaytime);
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
			DrawGrid(hwnd, { j,i }, EBrush(m_graph[i][j]));
		}
	}
	EndPaint(hwnd,&pt);
}
void Graph::MouseLB(const HWND& hwnd, const std::pair<int, int>& idx, EBrush color)
{
	pair<int, int> array_idx;
	ArrayCoordinate(idx, array_idx);
	// 이미 방문 했다면 리턴
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
	int dx[] = { -1, 1,0,0 ,-1,-1, 1,1};
	int dy[] = { 0, 0,-1,1 ,-1, 1,-1,1};

	pair<int, int> array_idx;
	ArrayCoordinate(m_startPos, array_idx);

	vector<vector<bool>> visited(Row,vector<bool>(Column,false));
	
	queue<pair < pair<int, int>,vector<pair<int,int> > >> q;
	q.push({ array_idx,vector<pair<int,int>>() });



	visited[array_idx.first][array_idx.second] = true;
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
				if (IsWall({ rx + 1,ry  }) && IsWall({ rx  ,ry + 1 }))
					continue;
				break;
			case 5:
				if (IsWall({ rx ,ry - 1}) && IsWall({ rx + 1,ry  }))
					continue;
				break;
			case 6:
				if (IsWall({ rx - 1 ,ry  }) && IsWall({ rx ,ry + 1 }))
					continue;
				break;
			case 7:
				if (IsWall({ rx ,ry - 1 }) && IsWall({ rx - 1,ry  }))
					continue;
				break;

			}
	
			if (m_graph[rx][ry] == int(EBrush::RedBrush))
			{
				for (auto& current : route)
				{
					pair<int, int> texture_idx;
					TextureCoordinate(current, texture_idx);
					m_graph[current.first][current.second] = int(EBrush::OrangeBrush);
					DrawGrid(hwnd, { texture_idx.first,texture_idx.second },EBrush::OrangeBrush, DelayTime);
					
				}
				goto search;
			}
			visited[rx][ry] = true;
			vector<pair<int, int>> lroute = route;
			lroute.push_back({ rx,ry });

			q.push({ {rx,ry} , lroute });
			
			m_graph[rx][ry] = int(EBrush::GrayBrush);
			m_visited[rx][ry] = true;
			DrawGrid(hwnd, { ry,rx },EBrush::GrayBrush,DelayTime);
			
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

vector<vector<int>> costs;

void Graph::AStarDistance(const HWND& hwnd,priority_queue<Node, vector<Node>>& q, const std::pair<int, int>& pos)
{
	int dx[] = { -1, 1,0,0 ,-1,-1, 1,1 };
	int dy[] = { 0, 0,-1,1 ,-1, 1,-1,1 };
	
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
			if (i < 4) 
				node = Node(texturecoordinate_idx, m_targetPos, preNode.currentCost + 10);
			else
				node = Node(texturecoordinate_idx, m_targetPos, preNode.currentCost + 14);
			if (costs[rx][ry] > node.total)
			{
				costs[rx][ry] = min(costs[rx][ry], node.total);
				q.emplace(node);
			}
			break;
		}
		if (rx < 0 || ry < 0 || Row <= rx || Column <= ry)
			continue;
		if (m_visited[rx][ry] || IsWall({ rx,ry }))
			continue;

		DrawGrid(hwnd, texturecoordinate_idx, EBrush::GreenBrush,DelayTime);

		//대각선의 경우에
		// is Wall 은 arrayidx
		switch (i)
		{
		case 4:
			if (IsWall({ rx + 1,ry }) && IsWall({ rx  ,ry + 1 }))
				continue;
			break;
		case 5:
			if (IsWall({ rx ,ry - 1 }) && IsWall({ rx + 1,ry }))
				continue;
			break;
		case 6:
			if (IsWall({ rx - 1 ,ry }) && IsWall({ rx ,ry + 1 }))
				continue;
			break;
		case 7:
			if (IsWall({ rx ,ry - 1 }) && IsWall({ rx - 1,ry }))
				continue;
			break;
		default:
			node = Node(texturecoordinate_idx, m_targetPos, preNode.currentCost + 10);
			if(costs[rx][ry] > node.total)
			{
				costs[rx][ry] = min(costs[rx][ry], node.total);
				q.emplace(node);
			}
			
			// int를 LPCWSTR 문자열로 변환
			
			wchar_t buffer[20];
			swprintf_s(buffer, sizeof(buffer) / sizeof(wchar_t), L"%d", costs[rx][ry]);
			TextGrid(hwnd, texturecoordinate_idx, buffer);
			continue;
		}
		node = Node(texturecoordinate_idx, m_targetPos, preNode.currentCost + 14);
		if (costs[rx][ry] > node.total)
		{
			costs[rx][ry] = min(costs[rx][ry], node.total);
			q.emplace(node);
		}
		costs[rx][ry] = min(costs[rx][ry], node.total);

		wchar_t buffer[20];
		swprintf_s(buffer, sizeof(buffer) / sizeof(wchar_t), L"%d", costs[rx][ry]);
		TextGrid(hwnd, texturecoordinate_idx, buffer);

		
	}
	
}
#include <stack>

void ChkLink(stack<Node> s, stack<Node>& rt, Node node)
{
	//node는 마지막 targetNode임 .
	//
	Node current = node;
	while (!s.empty())
	{
		Node top = s.top();
		int distance = current.currentCost - top.currentCost;
	
		pair<int, int> idx_distance = current - top;
		if (idx_distance.first < 2 && idx_distance.second < 2) 
		{
			if (distance == 14 || distance == 10)
			{
				rt.push(top);
				std::cout << "  top : " << top.idx.first << " - " << top.idx.second
					<< "  current : " << current.idx.first << " - " << current.idx.second
					<< "  distance : " << distance << "\n";
				current = top;
			}
		}
		
		s.pop();
	}
	

}
void Graph::AStar(const HWND& hwnd)
{
	costs.clear();
	costs.resize(Row, vector<int>(Column,INT_MAX));

	ResetVisited();
	auto sTime = chrono::high_resolution_clock::now();

	pair<int, int> array_idx;
	ArrayCoordinate(m_startPos, array_idx); //  m_startPos 는 texturecoordinate 임
	priority_queue<Node,vector<Node>> q; // Node에는 texturecoordinate로 입력

	Node node = Node(m_startPos.first, m_startPos.second, m_targetPos, 0);
	q.push(node);

	m_visited[array_idx.first][array_idx.second] = true; //  행렬
	AStarDistance(hwnd,q, array_idx);
	
	stack<Node> s;
	stack<Node> route;

	while (!q.empty())
	{
		Node current = q.top();
		q.pop();
		
		pair<int, int> array_idx;
		ArrayCoordinate(current.idx, array_idx);

		auto& [x, y] = array_idx;
		m_visited[x][y] = true;

		if (y == m_targetPos.first && x == m_targetPos.second)
		{
			ChkLink(s, route, current);
			break;
		}
		DrawGrid(hwnd, { y, x }, EBrush::GrayBrush, DelayTime);
		s.push(current);
		q.push(current);
		AStarDistance(hwnd,q, {x,y});
	}

	while (!route.empty())
	{
		auto [x, y] = route.top().idx;
		route.pop();
		DrawGrid(hwnd, { x, y }, EBrush::OrangeBrush, DelayTime);
	}
	double number = (chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3);
	wchar_t buffer[32];
	swprintf(buffer, 32, L"%lf 시간이 소요되었습니다.", number);
	string str = to_string((chrono::high_resolution_clock::now() - sTime).count() / pow(1000, 3));
	MessageBox(hwnd, buffer, L"AStart 소요시간", MB_OK);
	ResetVisited();
}
