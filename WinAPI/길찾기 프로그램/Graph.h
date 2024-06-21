#pragma once

#include "DrawModule.h"

class Graph : public DrawModule
{
public:
	Graph():Row(10),Column(10){};
	~Graph() {};
	void Initalize(const HWND& hwnd);

	//Window Message ���� �̺�Ʈ
	void PaintedDraw(const HWND& hwnd); // WM_PAINT �� ��
	void MouseLB(const HWND& hwnd, const std::pair<int,int>& idx, EBrush color);
	void SelectStart(const HWND& hwnd, const std::pair<int, int>& idx);
	void SelectEnd(const HWND& hwnd, const std::pair<int, int>& idx);

	FORCEINLINE bool ChkColor(const std::pair<int, int>& idx, EBrush& color) { return m_graph[idx.first][idx.second] == int(color); }
	bool IsVisited(const std::pair<int, int>& idx); //  ���콺 �� ������ �� ����Ŭ�� �ȵǰ��ϴ� ����

	void ResetVisited();
	void ResetGraph();
	
	//DrawModule �׸��� ����� �������̵�
	virtual void DrawGrid(const HWND& hwnd, const std::pair<int, int>& idx, EBrush color = EBrush::WhiteBrush) override; // 

	// ��ã�� �˰���
	void Dijkstra(const HWND& hwnd);
	void AStar(const HWND& hwnd);

public:
	std::vector<std::vector<int>> m_graph;
	std::vector<std::vector<bool>> m_visited;

	std::pair<int, int> m_startPos = { 0,0 };
	std::pair<int, int> m_targetPos = { 0,0 };
	
	int Row;
	int Column;
};

