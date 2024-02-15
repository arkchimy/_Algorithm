#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 10000001

using namespace std;

typedef unsigned long long ll;

ll vec[MAX];
vector<ll> prime;

ll a = 0, b = 0;

void sieve()
{
	for (ll i = 2; i <= sqrt(MAX); i++)
	{
		if (vec[i] == 0)
			continue;

		for (ll k = i * 2; k/i < MAX/i; k += i)
			vec[k] = 0;
		for (ll k = i * i; k/i < MAX /i; k *= i)
			prime.push_back(k);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> b;
	for (int i = 2; i < MAX; i++)
		vec[i] = i;

	int cnt = 0;

	sieve();
	sort(prime.begin(), prime.end());

	for (int i = a; i <= b; i++)
	{

		if (binary_search(prime.begin(), prime.end(), i))
			cnt++;

	}
	cout << cnt;
	return 0;
}