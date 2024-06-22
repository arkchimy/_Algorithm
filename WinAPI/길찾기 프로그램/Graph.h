#pragma once

#include "DrawModule.h"
#include <cmath>
#include <queue>

struct Node
{
	Node() = default;
	Node(int x, int y, std::pair<int, int>& target,int cost)
		:idx({ x,y })
	{
		currentCost = cost;
		int len = min(std::abs(target.first - x), std::abs(target.second - y));
		total = len * 14 + abs(target.first - len) * 10 + len * 14 + abs(target.second - len) * 10;
		needCost = total - currentCost;
	};
	std::pair<int, int> idx;

	int currentCost; //���� �ҿ�� cost
	int needCost; // ������ �ʿ��� �Ÿ�
	int total; // current_cost + needCost
	bool operator < (const Node& n2) const
	{
		if (total == n2.total)
		{
			if (needCost != n2.needCost)
				return needCost > n2.needCost;
			return currentCost > n2.currentCost;
		}
		return total > n2.total;
	}
};

class Graph : public DrawModule
{
public:
	Graph():Row(10),Column(10){};
	~Graph() {};
public:
	
	void Initalize(const HWND& hwnd);

	//Window Message ���� �̺�Ʈ
	void PaintedDraw(const HWND& hwnd); // WM_PAINT �� ��
	void MouseLB(const HWND& hwnd, const std::pair<int,int>& idx, EBrush color);

	void SelectStart(const HWND& hwnd, const std::pair<int, int>& idx);
	void SelectEnd(const HWND& hwnd, const std::pair<int, int>& idx);

	// ���� ����
	FORCEINLINE bool ChkColor(const std::pair<int, int>& idx, EBrush& color) { return m_graph[idx.first][idx.second] == int(color); }
	bool IsVisited(const std::pair<int, int>& idx); //  ���콺 �� ������ �� ����Ŭ�� �ȵǰ��ϴ� ����
	bool IsWall(const std::pair<int, int>& idx);

	// ���� 
	void ResetVisited();
	void ResetGraph();
	
	//DrawModule �׸��� ����� �������̵�
	virtual void DrawGrid(const HWND& hwnd, const std::pair<int, int>& idx, EBrush color = EBrush::WhiteBrush) override; // 

	// ��ã�� �˰���
	void Dijkstra(const HWND& hwnd);
	void AStar(const HWND& hwnd);
	void AStarDistance(std::priority_queue<Node, std::vector<Node>, std::less<Node>>& q, const std::pair<int, int>& pos);

public:

	

	std::vector<std::vector<int>> m_graph;
	std::vector<std::vector<bool>> m_visited;

	std::pair<int, int> m_startPos = { 0,0 };
	std::pair<int, int> m_targetPos = { 0,0 };
	
	int Row;
	int Column;
};

