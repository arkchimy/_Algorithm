#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

vector< vector<int >> graph;
vector<int> d;

int main()
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

	int n, m;
	cin >> n >> m;


	graph.resize(n + 1, vector<int>(n + 1, INT_MAX));
	d.resize(n + 1, INT_MAX);

	int a, b, distance;
	while (m--)
	{
		cin >> a >> b >> distance;
		q.push({ distance,{a,b} });
		graph[a][b] = distance;
		graph[b][a] = distance;
	}
	cin >> a >> b;


	d[a] = 0;
	for (int i = 1; i <= n; i++)
		graph[i][i] = 0;

	while (!q.empty())
	{
		pair<int, pair<int, int>> top = q.top();
		distance = q.top().first;
		pair<int, int> p = q.top().second;
		q.pop();
			
		graph[p.first][p.second] = graph[p.first][p.second] < graph[p.first][p.first] + graph[p.first][p.second] ? graph[p.first][p.second] : graph[p.first][p.first] + graph[p.first][p.second];
		graph[p.second][p.first] = graph[p.first][p.second];
	}
	cout << graph[a][b];

}