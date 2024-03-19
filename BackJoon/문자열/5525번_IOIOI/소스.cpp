
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m,cnt = 0;
	string str;
	cin >> n >> m >> str;

	for (int i = 0; i < m; i++)
	{
		if (str[i] == 'O')
			continue;
		int len = 0;
	
		while (str[i + 1] == 'O' && str[i + 2] == 'I')
		{
			len++;
			if (len == n)
			{
				cnt++;
				len--;
			}
			i += 2;
		}
	}
	cout << cnt;
}



// 50Á¡ ¸ÂÀ½
//int main()
//{
//	int n,m;
//	string str;
//	cin >> n >> m >> str;
//
//	string target ="";
//	for (int i = 0; i < n; i++)
//		target += "IO";
//	target += "I";
//
//
//	int start = 0;
//	int cnt = 0;
//	while (start != m )
//	{
//		string temp = str.substr(start, n * 2 + 1);
//
//		if (target.compare(temp) == 0)
//		{
//			cnt++;
//			start += 2;
//		}
//		else
//			start++;
//	}
//
//	cout << cnt;
//}