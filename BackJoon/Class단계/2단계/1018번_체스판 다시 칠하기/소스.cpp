#include<iostream>
#include <vector>
#include <limits.h>

using namespace std;

string str[2];
vector<string> vec;
int n, m;

int sol(int a, int b)
{
	int cnt1 = 0, cnt2 = 0;

	for (int i = a; i < a + 8; i++)
	{
		int idx = 0;
		for (int j = b; j < b + 8; j++)
		{
			if (i % 2 == 0)
			{
				if (vec[i][j] != str[0][idx])
				{

					cnt1++;
				}
				if (vec[i][j] != str[1][idx])
				{

					cnt2++;
				}
			}
			else
			{
				if (vec[i][j] != str[1][idx])
				{
					char a = vec[i][j];
					char b = str[1][idx];
					cnt1++;
				}
				if (vec[i][j] != str[0][idx])
				{
					char a = vec[i][j];
					char b = str[0][idx];
					cnt2++;
				}
			}
			idx++;

		}
	}
	return min(cnt1, cnt2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	

	vec.resize(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	for (int i = 0; i < 8; i++)
	{
		if (i % 2 == 0)
		{
			str[0] += 'W';
			str[1] += 'B';
		}
		else
		{
			str[0] += 'B';
			str[1] += 'W';
		}
	}
	int result = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i + 8 > n || j + 8 > m)
				continue;
			result = min(sol(i, j),result);
		}
	}
	cout << result;
	
}