#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> node;

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

	int a, b, c;
	int sum = 0;
	int cost = 0;

	while (1)
	{
		int n, m;
		cin >> n >> m;

		sum = 0;
		cost = 0;
		
		if (!n && !m)
			break;

		node.clear();
		node.resize(n);

		for (int i = 0; i < n; i++)
			node[i] = i;

		priority_queue<pair<int, pair<int, int>>> q;
		while (m--)
		{
			cin >> a >> b >> c;
			q.push({ -c,{a,b} });
			sum += c;
		}


		while (!q.empty())
		{
			int distance = q.top().first;
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
				cost -= distance;
			}

		}
		cout << sum - cost << "\n";
	}
	
}