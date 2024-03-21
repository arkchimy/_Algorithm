#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int temp = 1;
	int cnt = 0; // 물이있는 물 병
	while (temp <= n)
	{
		if ((temp & n) == temp)
			cnt++;
		temp = temp << 1;
	}

	int num = n;
	while (cnt > m)
	{
		num += 1;
		temp = 1;
		cnt = 0;
		while (temp <= num)
		{
			if ((num & temp) == temp)
				cnt++;
			temp = temp << 1;
		}
	}
	cout << num - n;
}