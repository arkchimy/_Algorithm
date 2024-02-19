#include <iostream>

using namespace std;

int dp[31];
int main()
{
	int n;
	cin >> n;

	dp[1] = 0;
	dp[2] = 3;


	for (int i = 3; i < 31; i++) 
	{
		if (i % 4 == 0)
			dp[i] = 3 * dp[i - 2] + 2;
		else if (i % 2 == 0)
			dp[i] = 3 * dp[i - 2];
		else
			dp[i] = 0;
	}

	cout << dp[n];
}