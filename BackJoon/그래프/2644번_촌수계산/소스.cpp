#include <iostream>
#include <vector>
#include <array>

using namespace std;

typedef std::array<std::array < int, 101>, 101> Array;
Array arr;
vector<bool> visited(101, false);

//팁을 드리면 
// 필기하면 생각
int result = -1;
void DFS(int start, int target,int cost)
{
	if (arr[start][target]) 
	{
		result = cost + 1;
		return;
	}

	visited[start] = true;

	for (int i = 1; i <= 100; i++)
	{
		if (!visited[i] && arr[start][i]) 
			DFS(i,target,cost + 1);
		
	}
	
}
int main()
{
	
	int n, a, b, m;

	cin >> n >> a >> b >> m;

	pair<int, int> p;
	//[0,0,0,0,0,0,0,1]
	while (m--)
	{
		cin >> p.first >> p.second;
		arr[p.first][p.second] = 1;
		arr[p.second][p.first] = 1;
	}
	
	DFS(a, b,0);
	cout << result;
	
}