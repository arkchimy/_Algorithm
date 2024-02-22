#include <iostream>
#include <vector>
#include <queue>
#include <limits>

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
	int n, m;
	cin >> n >> m;

	node.resize(n + 1);// 0이 존재하지않음

	for (int i =0; i <=n; i++)
		node[i] = i;

	priority_queue < pair<int, pair<int, int>>> q;

	int a, b, c;
	while (m--)
	{
		cin >> a >> b >> c;
		q.push({ -c,{a,b} });
	}

	int sum = 0;
	int last = 0;
	while (!q.empty())
	{
		int cost = q.top().first;
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
			
			sum -= cost;
			last = cost;
		}
		
	}
	// 마지막 cost는 제거
	cout << sum + last;
}