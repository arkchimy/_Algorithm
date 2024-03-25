#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int dx[] = { 1,0,1,0,-1,0,1,0,-3,0,1,0,-1,0,1,0 };
int dy[] = { -3,1,-1,1,1,1,-1,1,1,1,-1,1,1,1,-1,1 };


int cnt;
bool bChk;
int dfs(pair<int,int> current,pair<int, int>& target, vector<vector<int>>& graph,int& n)
{
	cnt++;
	n++;
	n %= 16;
	if (current == target)
	{
		return cnt;
	}
	current.first += dx[n];
	current.second += dy[n];

	return dfs(current,target,graph,n);
	
}
int main()
{
	vector<vector<int>> graph;

	int n;
	pair<int, int> start;
	cin >> n;
	cin >> start.first >> start.second;

	n = pow(2, n);
	graph.resize(n,vector<int>(n,0));
	n = -1;
	cout << dfs({-1,3},start, graph, n);
	
}