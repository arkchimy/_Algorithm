#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
/*
   N���� �� �߿��� � ���� �ٸ� �� �� ���� ������ ��Ÿ�� �� �ִٸ� �� ���� ������(GOOD)���� �Ѵ�.

   N���� ���� �־����� �� �߿��� ���� ���� ������ �� ������ ����϶�.

   ���� ��ġ�� �ٸ��� ���� ���Ƶ� �ٸ� ���̴�.
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
	// ���� ���� ���� �Ұ���
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