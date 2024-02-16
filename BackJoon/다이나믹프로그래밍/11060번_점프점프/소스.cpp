#include <iostream>
#include <vector>

using namespace std;

int dp[1001];
int main()
{
	int n;
	int num;
	vector<int> vec;


	cin >> n;
	while (n--)
	{
		cin >> num;
		vec.push_back(num);
	}
	for (int i = 1; i < vec.size(); i++)
	{
		for (int k = 1; 0 <= i - k; k++)
		{
			if (vec[i - k] >= k)
			{
				if (dp[i] == 0)
					dp[i] = dp[i - k] + 1;
				else
					dp[i] = min(dp[i], dp[i - k] + 1);
			}
		}
		if (!dp[i])
		{
			cout << -1;
			return 0;
		}
	}
	
	cout << dp[vec.size() - 1];

}