#include <iostream>
#include <string>
#include <vector>

#define MAX 9
using namespace std;


int num[MAX];


int n, m;
void dfs(string str,vector<bool> visited)
{
	if (str.size() == m)
	{
		for (int i = 0; i < str.size(); i++)
			cout << str[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			dfs(str + to_string(i),visited);
		}
	}

}
int main()
{

	cin >> n >> m;
	

	for (int i = 1; i <= n; i++)
		num[i] = i;
	for (int i = 1; i <= n; i++)
	{
		vector<bool> visited(MAX, false);
		for (int k = 0; k < i; k++)
			visited[k] = true;
		dfs(to_string(i),visited);
	}
}