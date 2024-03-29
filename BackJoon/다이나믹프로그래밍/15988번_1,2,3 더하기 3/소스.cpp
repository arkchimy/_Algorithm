#include <iostream>
#include <vector>

using namespace std;

long long dp[1000001];
int main()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 1000001; i++)
	{
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
	}
	int n;
	cin >> n;
	vector<long long > vec;
	while (n--)
	{
		int temp;
		cin >> temp;
		vec.emplace_back(dp[temp]);
	}
	for (const long long& num : vec)
		cout << num << "\n";
}
