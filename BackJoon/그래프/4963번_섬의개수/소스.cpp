#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { -1,1,0 ,0 };
int dy[] = { 0, 0,-1,1 };

void bfs(pair<int,int> start,vector<vector<int>>& vec)
{
	vec[start.first][start.second] = 2;
	queue<pair<int, int>> q;
	q.push(start);
	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();

		int rx, ry;
		for (int i = 0; i < 4; i++)
		{
			rx = front.first + dx[i];
			ry = front.second + dy[i];
			if (rx < 0 || vec.size() <= rx || ry < 0 || vec[0].size() <= ry)
				continue;
			if (vec[rx][ry] == 1)
			{
				vec[rx][ry] = 2;
				q.push({ rx,ry });
			}
		}
		for (int i = 0; i < 2; i++)
		{
			rx = front.first + dx[i] ;
			ry = front.second + dy[i] + 1;
			if (0 <= rx && rx < vec.size() && 0 <= ry && ry < vec[0].size())
			{
				if (vec[rx][ry] == 1)
				{
					vec[rx][ry] = 2;
					q.push({ rx,ry });
				}
			}
			ry = front.second + dy[i] - 1;
			if (0 <= rx && rx < vec.size() && 0 <= ry && ry < vec[0].size())
			{
				if (vec[rx][ry] == 1)
				{
					vec[rx][ry] = 2;
					q.push({ rx,ry });
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	pair<int, int> p;
	
	while (1)
	{
		cin >> p.first >> p.second;
		if (p.first == 0 && p.second == 0)
			break;
		vector<vector<int>> vec;
		vec.resize(p.second);

		for (int i = 0; i < p.second; i++)
		{
			vec[i].reserve(p.first);
			for (int j = 0; j < p.first; j++)
			{
				int temp;
				cin >> temp;
				vec[i].emplace_back(temp);
			}
		}
		int cnt = 0;
		for (int i = 0; i < p.second; i++)
		{
			for (int j = 0; j < p.first; j++)
			{
				if (vec[i][j] == 1)
				{
					bfs({ i,j }, vec);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}


}