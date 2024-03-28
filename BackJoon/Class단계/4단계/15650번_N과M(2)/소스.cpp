#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> vec;


vector<string> result;
int n, m;

void dfs(int node,string str,vector<bool> visited)
{
	if (str.size() == m) 
	{
		result.emplace_back(move(str));
		return;
	}
	for (int i = 1; i < visited.size(); i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			dfs(i, str + to_string(i), visited);
		}
	}

}
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	vec.reserve(n + 1);
	

	for (int i = 0; i <= n; i++)
		vec.emplace_back(i);
	
	for (int i = 1; i <= n; i++) 
	{
		vector<bool> visited;
		visited.resize(n + 1);
		for(int k =0; k <= i; k++)
			visited[k] = true;

		dfs(i, to_string(i), visited);
	}
	sort(result.begin(), result.end());

	for (string str : result)
	{
		for (int i = 0; i < str.size(); i++)
			cout << str[i] << " ";
		cout << "\n";
	}
	
}	