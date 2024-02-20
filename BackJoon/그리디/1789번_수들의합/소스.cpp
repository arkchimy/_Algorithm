#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ll n;

	cin >> n;

	ll sum = 0;
	ll cnt = 0;
	for (ll i = 1; i <= n; i++)
	{
		sum += i;
		cnt++;
		if (n < sum)
		{
			cnt--;
			break;
		}
		if (n == sum)
			break;
	}
	cout << cnt;

}