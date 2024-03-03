#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
/*
   N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 “좋다(GOOD)”고 한다.

   N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.

   수의 위치가 다르면 값이 같아도 다른 수이다.
*/

vector<ll> vec;
ll cnt;


int main()
{
	ll n;
	cin >> n;

	vec.reserve(n);
	while (n--)
	{
		ll temp;
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	// 가장 작은 수는 불가능
	for (ll i = 3; i <= vec.size(); i++)
	{
		auto iter = vec.begin() + i - 1;
		if (iter == vec.end())
			break;
		ll temp;

		while (iter != vec.begin())
		{
			iter--;
			temp = vec[i] - *(iter);
			auto iter2 = lower_bound(vec.begin(), vec.end(), temp);
			
		}
	}
	cout << cnt;
}