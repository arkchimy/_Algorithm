#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
vector<vector<int>> vec;
vector<vector<bool>> visited;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void DFS(pair<int,int> start,const int& height)
{
	stack<pair<int, int>> s;
	s.push({ start.first,start.second });
	while (!s.empty())
	{
		pair<int, int> top = s.top();
		s.pop();

		int rx, ry;
		for (int i = 0; i < 4; i++)
		{
			rx = top.first + dx[i];
			ry = top.second + dy[i];

			if (rx < 0 || ry < 0 || vec.size() <= rx || vec.size() <= ry) continue;
			if (vec[rx][ry] > height && !visited[rx][ry]) 
			{
				s.push({ rx,ry });
				visited[rx][ry] = true;
			}
		}
	}
}
void reset()
{
	for (int i = 0; i < visited.size(); i++)
		for (int k = 0; k < visited.size(); k++)
			visited[i][k] = false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	
	vec.reserve(n);
	visited.resize(n);
	for (int i = 0; i < n; i++)
		visited[i] = vector<bool>(n, false);

	for(int i =0; i < n ; i++)
	{
		vector<int> temp;
		temp.reserve(n);
		int num;
		for (int k = 0; k < n; k++)
		{
			cin >> num;
			temp.push_back(num);
		}
		vec.push_back(temp);
	}

	vector<int> result;
	for (int height = 1; height < 101; height++)
	{
		int cnt = 0;
		for (int i = 0; i < vec.size(); i++) 
		{
			for (int k = 0; k < vec.size(); k++)
			{
				if (vec[i][k] > height && !visited[i][k])
				{
					DFS({ i,k }, height);
					cnt++;
				}
			}
		}
		result.push_back(cnt);
		reset();
	}
	sort(result.rbegin(), result.rend());
	if (result[0] == 0)
		cout << 1;
	else
		cout << result[0];
}