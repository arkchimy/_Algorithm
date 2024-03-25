#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void bfs(int n, int m, vector<vector<int>>& graph)
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	graph[0][0] = -1;
	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();

		if (front.first == n && front.second == m)
			break;
		int rx, ry;
		for (int i = 0; i < 4; i++)
		{
			rx = front.first + dx[i];
			ry = front.second + dy[i];

			if (rx < 0 || ry < 0 || graph.size() <= rx || graph[0].size() <= ry)
				continue;
			if (graph[rx][ry] == 1)
			{
				q.push({rx,ry});
				graph[rx][ry] = graph[front.first][front.second] - 1;
			}
		}

	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph;

	graph.resize(n);
	
	for(int i =0; i < n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.size(); j++)
			graph[i].emplace_back(temp[j] - 48);
	}
	bfs(n -1 , m - 1, graph);

	cout << -graph[n - 1][m - 1];
}