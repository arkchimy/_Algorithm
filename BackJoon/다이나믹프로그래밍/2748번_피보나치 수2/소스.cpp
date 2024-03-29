#include <iostream>


using namespace std;
typedef unsigned long long ll;

ll dp[91];

ll fib(int n)
{
	return dp[n] = dp[n - 1] + dp[n - 2];
}
int main()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	int n;
	cin >> n;

	for (int i = 3; i <= n; i++)
		fib(i);
	cout << dp[n];
}