#include <iostream>
#include <vector>


using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int cnt; // 0

void DFS(int x)
{
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++)
	{
		if (visited[graph[x][i]] == false)
		{
			cnt++;
			DFS(graph[x][i]);

		}
	}
}
// 2차원배열
int main()
{
	int n, m;
	
	cin >> n >> m;

	graph.resize(n + 1); // 0 번쨰꺼 안씀
	visited.resize(n + 1 , false); // 영상하고 똑같이 

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	DFS(1);

	cout << cnt;
}

//
//vector<int> nodes;
//int GetParent(int n)
//{
//	if (nodes[n] == n)
//		return n;
//	return nodes[n] = GetParent(nodes[n]);
//}
//
//int main()
//{
//
//	vector<pair<int, int>> p;
//
//	int n, m;
//	cin >> n >> m;
//	nodes.resize(n + 1);
//
//	for (int i = 0; i <= n ; i++)
//		nodes[i] = i;
//
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		p.emplace_back(a, b);
//	}
//
//	for (int i = 0; i < p.size(); i++)
//	{
//		int a = GetParent(p[i].first);
//		int b = GetParent(p[i].second);
//
//		if (a != b)
//		{
//			if (a < b)
//				nodes[b] = a;
//			else
//				nodes[a] = b;
//		}
//	}
//	for (int i = 1; i <= n; i++)
//		GetParent(i);
//	int cnt = -1;
//	for (int& node : nodes)
//	{
//		if (node == 1)
//			cnt++;
//	}
//	cout << cnt;
//}