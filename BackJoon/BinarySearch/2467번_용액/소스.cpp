#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

typedef long long ll;

int main()
{

	vector<ll> vec;
	int n;
	cin >> n;
	vec.reserve(n);
	int temp;
	while (n--)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	ll answer = INT_MAX;
	pair<ll, ll> p;
	for (ll& num : vec)
	{
		auto iter = upper_bound(vec.begin(), vec.end(),-num);
		
		if (iter == vec.end())
			iter--;

		if (*iter == num)// 끝 요소라는 뜻
			continue;

		if (abs(*iter + num) < answer)
		{
			answer = abs(*iter + num);
			p = { min(*iter,num),max(*iter,num)};
		}

		if (iter != vec.begin() && iter != vec.end())
		{
			iter--;
			if (*iter != num && abs(*iter + num) <= answer)
			{
				answer = abs(*iter + num);
				p = { min(*iter,num),max(*iter,num) };
			}
		}
	}
	cout << p.first << " " << p.second;
}
