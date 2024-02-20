#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>


using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> d;

void dijkstra(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int>> p;
	p.push({ start,0 });

	while (!p.empty())
	{
		int current = p.top().first;
		int distance = -p.top().second;
		p.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < graph[current].size(); i++)
		{
			int next = graph[current][i].first;
			int nextDistance = distance + graph[current][i].second;
			if (nextDistance < d[next])
			{
				d[next] = nextDistance;
				p.push({ next,-nextDistance });
			}
		}
	}
}
int main()
{
	int n, m;

	cin >> n >> m;
	int a, b, distance;

	graph.resize(n);
	d.resize(n,INT_MAX);
	while (m--)
	{
		cin >> a >> b >> distance;
		a -= 1;
		b -= 1;
		graph[a].emplace_back( b,distance );
	}
	cin >> a >> b;
	a -= 1;
	b -= 1;
	dijkstra(a);
	cout << d[b];
}