#pragma once

#include "DrawModule.h"
#include <cmath>
#include <queue>
#include <iostream>

// texturecoordinate 변환된 값
struct Node
{
	Node() = default;
	Node(int x, int y, std::pair<int, int>& target,int cost)
		:idx({ x,y })
	{
		currentCost = cost;
		int len = min(std::abs(target.first - x), std::abs(target.second - y));
		needCost = len * 14 +
			 (abs(target.first  - x ) - len) * 10 +
			 (abs(target.second - y ) - len) * 10;
		total = needCost + currentCost;
		/*std::cout << "  total : " << total << "  needCost : " << needCost << "  currentCost : " << currentCost << "\n";*/
	};
	Node(const std::pair<int, int> p, std::pair<int, int>& target, int cost)
		:Node(p.first, p.second, target, cost) {}
	
	std::pair<int, int> idx;

	int currentCost; //현재 소요된 cost
	int needCost; // 앞으로 필요한 거리
	int total; // current_cost + needCost
	bool operator < (const Node& n2) const
	{
		if (total == n2.total)
		{
			if (needCost != n2.needCost)
				return needCost > n2.needCost;
			return currentCost < n2.currentCost;
		}
		return total > n2.total;
	}
	std::pair<int,int> operator - (const Node& other)
	{
		return { abs(idx.first - other.idx.first) ,abs(idx.second - other.idx.second) };
	}
};

class Graph : public DrawModule
{
public:
	Graph():Row(10),Column(10){};
	~Graph() {};
public:
	
	void Initalize(const HWND& hwnd);

	//Window Message 관련 이벤트
	void PaintedDraw(const HWND& hwnd); // WM_PAINT 일 때
	void MouseLB(const HWND& hwnd, const std::pair<int,int>& idx, EBrush color);

	void SelectStart(const HWND& hwnd, const std::pair<int, int>& idx);
	void SelectEnd(const HWND& hwnd, const std::pair<int, int>& idx);

	// 판정 로직
	FORCEINLINE bool ChkColor(const std::pair<int, int>& idx, EBrush& color) { return m_graph[idx.first][idx.second] == int(color); }
	bool IsVisited(const std::pair<int, int>& idx); //  마우스 꾹 눌렀을 때 연속클릭 안되게하는 방지
	bool IsWall(const std::pair<int, int>& idx);

	// 리셋 
	void ResetVisited();
	void ResetGraph();
	void SearchBefore();
	
	//DrawModule 그리기 기능의 오버라이드
	virtual void DrawGrid(const HWND& hwnd, const std::pair<int, int>& idx, EBrush color = EBrush::WhiteBrush,float delaytime = 0.f); //  texturecoordinate
	virtual void TextGrid(const HWND& hwnd, const std::pair<int, int>& idx,LPCWSTR str);
	// 길찾기 알고리즘
	void Dijkstra(const HWND& hwnd);
	void AStar(const HWND& hwnd);
	void AStarDistance(const HWND& hwnd,std::priority_queue<Node, std::vector<Node>>& q, const std::pair<int, int>& pos);//arraycoordinate

private:

	std::vector<std::vector<int>> m_graph;
	std::vector<std::vector<bool>> m_visited;

	std::pair<int, int> m_startPos = { 0,0 };
	std::pair<int, int> m_targetPos = { 0,0 };
	
	int Row;
	int Column;
};

