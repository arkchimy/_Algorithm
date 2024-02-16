#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> m;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int cnt;
vector<int> result;
void BFS(pair<int, int> start)
{
	cnt++;
	int sum = 1;
	m[start.first][start.second] = 'X';

	queue<pair<int, int>> q;
	q.push(start);
	pair<int, int> front;
	while (!q.empty())
	{
		front = q.front();
		q.pop();
		int rx, ry;
		for (int i = 0; i < 4; i++)
		{
			rx = front.first + dx[i];
			ry = front.second + dy[i];
			if (rx < 0 || ry < 0 || m.size() <= rx || m.size() <= ry) continue;
			if (m[rx][ry] == '1')
			{
				m[rx][ry] = 'X';
				q.push({ rx,ry });
				sum++;
			}
		}
	}
	result.push_back(sum);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		m.push_back(temp);
	}
	for (int i = 0; i < m.size(); i++)
		for (int k = 0; k < m.size(); k++)
			if (m[i][k] == '1')
				BFS({ i,k });

	cout << cnt << "\n";

	sort(result.begin(), result.end());
	for (int sum : result)
		cout << sum << "\n";
}