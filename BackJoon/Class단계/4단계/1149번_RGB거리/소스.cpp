#include <iostream>


using namespace std;


int dp[1001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int cost[3] = {0,};
	cin >> n;


	for (int i = 1; i <= n; i++)
	{
		cin >> cost[0] >> cost[1] >> cost[2];
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[2];
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}



//시간 초과 dfs
//#include<iostream>
//#include <vector>
//#include <limits.h>
//using namespace std;
//
//int dx[] = { 1,1 ,1,1};
//int dy[] = { -1,1 ,-2,2};
//
//vector<vector<int>> vec;
//int result =INT_MAX;
//
//void sol(const pair<int,int>& current,int sum)
//{
//	if (current.first == vec.size() - 1)
//	{
//		result = min(result, sum);
//		return;
//	}
//	pair<int, int> p;
//	for (int i = 0; i < 4; i++)
//	{
//		p.first = current.first + dx[i];
//		p.second = current.second + dy[i];
//
//		if (p.first < 0 || p.second < 0 || vec.size() <= p.first || vec[0].size() <= p.second)
//			continue;
//
//		int temp = sum + vec[p.first][p.second];
//		if (temp >= result)
//			continue;
//
//		sol(p, temp);
//	}
//}
//int main()
//{
//
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int n;
//	cin >> n;
//	vec.resize(n,vector<int>(3));
//	
//	for(int i =0; i < n; i++)
//	{
//		for (int k = 0; k < 3; k++)
//			cin >> vec[i][k];
//	}
//
//	for (int i = 0; i < 3; i++) 
//	{
//		pair<int, int> p(0, i);
//		sol(p, vec[0][i]);
//	}
//	cout << result;
//}