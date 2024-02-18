#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


vector<pair<float, float>> nodes;
vector<pair<pair<int, int>,float>> graph;

vector<int> parents;


bool comp(const pair<pair<int, int>, float> p1, const pair<pair<int, int>, float> p2)
{
	return p1.second < p2.second;
}

int GetParent(int n)
{
	if (n == parents[n])
		return n;
	return parents[n] = GetParent(parents[n]);
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n;
	cin >> n;

	parents.resize(n);
	graph.resize(n);
	
	nodes.reserve(n);

	for (int i = 0; i < n; i++)
		parents[i] = i;

	float a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		nodes.push_back({ a,b });
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int k = i + 1; k < n; k++)
		{
			float distance = sqrt(pow(nodes[i].first - nodes[k].first,2) + pow(nodes[i].second - nodes[k].second,2));
			graph.push_back({ {i,k},distance });
		}
		
	}
	nodes.clear();

	sort(graph.begin(), graph.end(), comp);

	float result = 0.f;
	for (auto node : graph)
	{
		int a, b;

		a = GetParent(node.first.first);
		b = GetParent(node.first.second);
		if (a != b)
		{
			if (a < b)
				parents[b] = a;
			else
				parents[a] = b;
			result += node.second;
		}
	}

	cout << result;
	
}