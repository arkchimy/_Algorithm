#include <iostream>


using namespace std;


int dp[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	dp[0] = 0;
	dp[1] = 1; // 1
	dp[2] = 1; // 2 
	dp[3] = 3; // 1 + 2 , 2 + 1, 3 ,    =>   2 + 1 + 2 ,  3 + 2  , 2 + 3
	dp[4] = 3; // 1 + 2 + 1, 1 + 3 , 3 + 1  =>  1 + 3 + 1, 
	dp[5] = 4; //3 + 2   , 2 + 3 , 1 + 3 + 1  , 2 + 1 + 2,  => dp[i-2] + dp[i-1] - 2
	dp[6] = 5; // 1 + 3 + 2 , 2 + 3 + 1, 
	dp[7] = 9;
	dp[10] = 27;
	for (int i = 5; i < 100001; i++)
		dp[i] = (dp[i - 2] + dp[i - 2])% 1000000009;
	int n;
	cin >> n;
	while (n--)
	{
		int temp;
		cin >> temp;
		cout << dp[temp] << '\n';
	}
	
}