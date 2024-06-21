#pragma once

#include "DrawModule.h"

class Graph : public DrawModule
{
public:
	//Graph();

	void Initalize(const HWND& hwnd);
	void PaintedDraw(const HWND& hwnd);
	
	bool IsVisited(const std::pair<int, int>& idx); //  마우스 꾹 눌렀을 때 연속클릭 안되게하는 방지
	void ClickPos(LPARAM lParam, std::pair<int, int>& pos);

	void ResetVisited();
	void ResetGraph();
	
	// 길찾기 알고리즘
	void Dijkstra(const HWND& hwnd);
	void AStar(const HWND& hwnd);

	FORCEINLINE void startPos(const std::pair<int, int>& p) { m_startPos = p; }
	FORCEINLINE void targetPos(const std::pair<int, int>& p) { m_targetPos = p; }
	FORCEINLINE std::pair<int, int> startPos() { return m_startPos; }
	FORCEINLINE std::pair<int, int> targetPos() { return m_targetPos; }

public:
	std::vector<std::vector<int>> m_graph;
	std::vector<std::vector<bool>> m_visited;

	std::pair<int, int> m_startPos = { 0,0 };
	std::pair<int, int> m_targetPos = { 0,0 };
	
};

