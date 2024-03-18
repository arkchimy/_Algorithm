#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<pair<int, int>> graph;


int GetParent(const int& node)
{
	if (node == vec[node])
		return node;
	return vec[node] = GetParent(vec[node]);
}
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vec.resize(n + 1);
	for (int i = 1; i < vec.size(); i++)
		vec[i] = i;

	graph.reserve(m);
	pair<int, int> p;
	while (m--)
	{
		cin >> p.first >> p.second;
		graph.emplace_back(p);
	}
	for (int i = 0; i < graph.size(); i++)
	{
		int a = GetParent(graph[i].first);
		int b = GetParent(graph[i].second);
		if (a != b)
		{
			if (a < b)
				vec[b] = a;
			else
				vec[a] = b;
		}
	}

	for(int i =1; i <= n; i++)
		GetParent(i);
	int cnt = 0;
	sort(vec.begin(), vec.end());

	for (int i = 1; i <= n; i++)
	{
		 if(binary_search(vec.begin(), vec.end(), i))
			 cnt++;

	}
	
	cout << cnt;

}


// DFS  & BFS 로 문제 해결

//vector<bool> visited;
//vector<vector<int>> vec;
//
//int cnt;
//
//void dfs(int& start)
//{
//	visited[start] = true;
//	
//	for (int i = 0; i < vec[start].size(); i++)
//	{
//		if (visited[vec[start][i]] == false)
//			dfs(vec[start][i]);
//	}
//}
//
//void bfs(int& start)
//{
//	visited[start] = true;
//	queue<int> q;
//	q.push(start);
//	while (!q.empty())
//	{
//		int front = q.front();
//		q.pop();
//		for (int i = 0; i < vec[front].size(); i++)
//		{
//			if (visited[vec[front][i]] == false)
//			{
//				visited[vec[front][i]] = true;
//				q.push(vec[front][i]);
//			}
//		}
//	}
//	
//}


//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	visited.resize(n + 1,false);
//	vec.resize(n + 1);
//
//	while (m--)
//	{
//		pair<int, int> p;
//		cin >> p.first >> p.second;
//		vec[p.first].emplace_back(p.second);
//		vec[p.second].emplace_back(p.first);
//	}
//	for (int i = 1; i < vec.size(); i++)
//	{
//		for (int j = 0; j < vec[i].size(); j++)
//		{
//			if (visited[vec[i][j]] == false)
//			{
//				bfs(vec[i][j]);
//				cnt++;
//			}
//		}
//	}
//	for (int i = 1; i < visited.size(); i++)
//	{
//		if (visited[i] == false)
//			cnt++;
//	}
//	cout << cnt;
//}