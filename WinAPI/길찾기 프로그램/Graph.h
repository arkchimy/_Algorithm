#pragma once

#include "DrawModule.h"

class Graph : public DrawModule
{
public:
	//Graph();

	void Initalize(const HWND& hwnd);
	void PaintedDraw(const HWND& hwnd);
	
	bool IsVisited(const std::pair<int, int>& idx); //  ���콺 �� ������ �� ����Ŭ�� �ȵǰ��ϴ� ����
	void ClickPos(LPARAM lParam, std::pair<int, int>& pos);

	void ResetVisited();
	void ResetGraph();
	
	// ��ã�� �˰���
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

