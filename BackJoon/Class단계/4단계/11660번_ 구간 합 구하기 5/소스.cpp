#include <iostream>
#include <vector>

using namespace std;


int sol(const pair<int, int>& p1, const pair<int, int>& p2,vector<vector<int>>& vec)
{
	int sum = 0;
	for (int i = p1.first; i <= p2.first; i++)
	{
		for (int j = p1.second; j <= p2.second; j++)
			sum += vec[i][j];
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> vec(n + 1,vector<int>(n + 1));
	
	for(int i =1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> vec[i][j];
	}
	
	for(int i=0; i < m ; i++)
	{
		pair<int, int> start;
		pair<int, int> end;
		cin >> start.first >> start.second >>  end.first >> end.second;
		cout << sol(start, end,vec) << '\n';
	}
}