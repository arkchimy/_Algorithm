#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE 200001
int dp[SIZE];
int main()
{
	int start, target;

	cin >> start >> target;

	for (int i = 0; i <= SIZE - 1; i++)
		dp[i] = abs(start - i);

	for (int i = start + 1; i <= target; i++)
	{
		dp[i] = dp[i - 1] + 1;
		dp[i] = min(dp[i], dp[i + 1] + 1);
		if (i % 2 == 0) 
			dp[i] = min(dp[i], dp[i / 2] + 1);
		else
			dp[i] = min(dp[i], dp[(i - 1) / 2] + 2);

		if (i * 2 <= SIZE - 1)
		{
			dp[i * 2] = min(dp[i * 2], dp[i] + 1);

			if (i % 2 == 1)
				dp[i] = min(dp[i], dp[i * 2] );
		}
	}
	cout << dp[target];
}