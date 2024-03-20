#include <iostream>
#include <vector>
#include <queue>

using namespace std;




int dx[] = { -2,-2,+2,+2,+1,-1,+1,-1 };
int dy[] = { -1,+1,-1,+1,-2,-2,+2,+2 };
void bfs(const pair<int, int>& p, const pair<int, int>& t,vector<vector<int>>& graph)
{
	queue<pair<int, int>> q;
	q.push(p);

	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();

		if (t.first == front.first && t.second == front.second)
		{
			cout <<graph[front.first][front.second] << "\n";
			break;
		}
		int rx, ry;
		for (int i = 0; i < 8; i++)
		{
			rx = front.first + dx[i];
			ry = front.second + dy[i];
			if (rx < 0 || ry < 0 || graph.size() <= rx || graph[0].size() <= ry)
				continue;
			if (graph[rx][ry] == 0)
			{
				graph[rx][ry] = graph[front.first][front.second] + 1;
				q.push({ rx,ry });
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;

	int temp;
	while (n--)
	{
		
		vector<vector<int>> graph;

		cin >> temp;
		graph.resize(temp,vector<int>(temp,0));
		pair<int, int> start, goal;
		cin >> start.first >> start.second;
		cin >> goal.first >> goal.second;

		bfs(start, goal,graph);
	}
}