#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

priority_queue<pair<double,pair<int,int>>> q;

vector<pair<int, int>> vec;

vector<int> node;

int GetParent(int n)
{
	if (n == node[n])
		return n;
	return node[n] = GetParent(node[n]);
}
int main()
{
	int n, m;
	int a, b, c;

	double result = 0.f;
	cin >> n >> m;

	node.resize(n + 1);
	for (int i = 0; i <= n; i++)
		node[i] = i;

	vec.emplace_back( 0,0 );
	
	pair<int, int> start;
	for(int i =0; i < n; i++)
	{
		cin >> a >> b;
		if (a == b)
			start = { a,b };
		vec.emplace_back(a,b);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		a = GetParent(a);
		b = GetParent(b);
		if (a < b) 
			node[b] = a;
		else 
			node[a] = b;

	}
	int start_idx = start.first;

	for(int i = 1; i < n ;i++)
		for (int j = i + 1; j <= n; j++)
		{
			double distance = sqrt(pow(vec[i].first - vec[j].first, 2) + pow(vec[i].second - vec[j].second,2));
			q.push({ -distance,{i,j} });
		}
	while (!q.empty())
	{
		double cost = -q.top().first;
		pair<int, int> top = q.top().second;

		q.pop();
		a = GetParent(top.first);
		b = GetParent(top.second);
		if (a != b)
		{
			if (a < b)
				node[b] = a;
			else
				node[a] = b;
			result += cost;
		}
	}
	printf("%.2lf", result);
}