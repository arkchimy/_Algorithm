#pragma once
class Graph
{
public:
	void Initalize(const HWND& hwnd);
	void PaintedDraw(const HWND& hwnd);
	void DrawGrid(const HWND& hwnd, const std::pair<int, int>& idx); // GetDC�� �̿��� Draw
	bool IsVisited(const std::pair<int, int>& idx); //  ���콺 �� ������ �� ����Ŭ�� �ȵǰ��ϴ� ����
	void ClickPos(LPARAM lParam, std::pair<int, int>& pos);
	void ResetVisited();
	void ResetGraph();
	void Dijkstra(const HWND& hwnd);


	FORCEINLINE void startPos(const std::pair<int, int>& p) { m_startPos = p; }
	FORCEINLINE void targetPos(const std::pair<int, int>& p) { m_targetPos = p; }
	FORCEINLINE std::pair<int, int> startPos() { return m_startPos; }
	FORCEINLINE std::pair<int, int> targetPos() { return m_targetPos; }

	void WhiteFill(const std::pair<int, int>& node);
	void GreenFill(const std::pair<int, int>& node);
	void RedFill(const std::pair<int, int>& node);
	void BlackFill(const std::pair<int, int>& node);

private:
	std::vector<std::vector<int>> m_graph;
	std::vector<std::vector<bool>> m_visited;

	std::pair<int, int> m_startPos = { 0,0 };
	std::pair<int, int> m_targetPos = { 0,0 };
	
};

