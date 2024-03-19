#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


vector<vector<int>> graph;

void init(pair<int, int>& goal)
{
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	for (int i = 0; i < n; i++)
		graph[i].resize(m);
	
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			if (temp == 2)
			{
				goal = { i,j };
				graph[i][j] = 0;
			}
			else
				graph[i][j] = temp;
			
		}
	}
}

void bfs(pair<int, int>& start)
{
	queue<pair<int,int>> q;
	q.push(start);

	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();

		int rx, ry;
		for (int i = 0; i < 4; i++)
		{
			rx = front.first + dx[i];
			ry = front.second + dy[i];
			if (rx < 0 || ry < 0 || graph.size() <= rx || graph[0].size() <= ry)
				continue;
			if (graph[rx][ry] == 1) 
			{
				graph[rx][ry] = graph[front.first][front.second] - 1;
				q.push({ rx,ry });
			}

		}
	}
}
int main()
{
	pair<int, int> goal;
	init(goal);

	bfs(goal);
	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph[0].size(); j++)
		{
			if (graph[i][j] == 1)
				cout << -1 << " ";
			else
				cout << -graph[i][j] << " ";
		}
		cout << "\n";
	}

	
}
