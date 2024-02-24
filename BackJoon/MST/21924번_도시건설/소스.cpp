#include <iostream>
#include <queue>
#include <vector>

using namespace std;


typedef long long ll;
vector<ll> node;
priority_queue<pair<ll, pair<ll, ll>>> q;

ll GetParent(ll n)
{
	if (n == node[n])
		return n;
	return node[n] = GetParent(node[n]);
}
int main()
{
	ll n, m;

	cin >> n >> m;
	node.resize(n + 1);

	// 자신으로 초기화
	for (ll i = 1; i <= n; i++)
		node[i] = i;

	ll a, b,c;
	ll sum = 0;
	ll cost = 0;
	while (m--)
	{
		cin >> a >> b >> c;
		q.push({ -c,{a,b} });
		sum += c;
	}
	

	while (!q.empty())
	{
		ll distance = -q.top().first;
		pair<ll, ll> top = q.top().second;
		
		q.pop();

		a = GetParent(top.first);
		b = GetParent(top.second);
		if (a != b)
		{
			if (a < b)
				node[b] = a;
			else
				node[a] = b;
			cost += distance;
		}
	}
	ll before = GetParent(1);
	for (ll i = 1; i <= n; i++)
	{
		if (before != GetParent(i))
		{
			cout << "-1";
			return 0;
		}
		
	}

	cout << sum - cost;
}