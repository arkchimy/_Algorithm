#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> node;
vector<pair<pair<int, int>, int>> graph;

int weight;

bool comp(const pair<pair<int, int>, int> p1, const pair<pair<int, int>, int> p2)
{
	return p1.second < p2.second;
}
int GetParent(int n)
{
	if (n == node[n])
		return n;
	return node[n] = GetParent(node[n]);
}
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n, m;
	cin >> n >> m;
	node.resize(n + 1);

	for (int i = 0; i < node.size(); i++)
	{
		node[i] = i;
	}
	int a, b , c;
	graph.reserve(m);
	while (m--)
	{
		cin >> a >> b >> c;
		graph.push_back({ {a,b},c });
	}

	sort(graph.begin(), graph.end(), comp);
	for (auto line : graph)
	{
		a = GetParent(node[line.first.first]);
		b = GetParent(node[line.first.second]);
		if (a != b)
		{
			if (a < b)
				node[b] = a;
			else
				node[a] = b;
			weight += line.second;
		}
	}

	cout << weight;
}
