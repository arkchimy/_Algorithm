#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<bool> visited;
vector<vector<int>> vec;
void reset()
{
	for (int i = 0; i < visited.size(); i++)
		visited[i] = false;
}

void DFS(int start)
{
	cout << start << " ";
	visited[start] = true;
	for_each(vec[start].begin(), vec[start].end(), [](int num)
		{
			if (visited[num] == false)
				DFS(num);
		});
}
void BFS(int start)
{
	
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		
		cout << front << " ";
		for (const int idx : vec[front])
		{
			if (!visited[idx])
			{
				visited[idx] = true;
				q.push(idx);
			}
		}

	}
}
int main()
{
	int n, m, s;
	cin >> n >> m >> s;


	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	visited.resize(n + 1);
	vec.resize(n + 1);
	pair<int, int> p;
	while (m--)
	{
		cin >> p.first >> p.second;
		vec[p.first].emplace_back(p.second);
		vec[p.second].emplace_back(p.first);
	}
	for (vector<int>& v : vec)
	{
		sort(v.begin(), v.end());
	}
	DFS(s);
	cout << "\n";
	reset();
	BFS(s);
}