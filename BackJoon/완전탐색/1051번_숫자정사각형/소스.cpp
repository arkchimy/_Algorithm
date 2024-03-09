//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<string> vec;
//vector<int> result;
//void Sol(const pair<int, int>& p)
//{
//	int len = 1;
//
//	char data = vec[p.first][p.second];
//	while (1)
//	{
//
//		int dx = p.first + len;
//		int dy = p.second + len;
//		if (vec.size() <= dx || vec[0].size() <= dy)
//			break;
//		if (vec[dx][p.second] == data && data == vec[p.first][dy] && data == vec[dx][dy])
//		{
//			result.emplace_back((len + 1) * (len + 1));
//		}
//		len++;
//	}
//
//
//}
//int main()
//{
//
//    // 모든 행렬에 시작지점과 꼭지점의 데이터를 비교 3개가 전부 같다면 넓이를 저장.
//
//	int n, m;
//	cin >> n >> m;
//
//	string temp;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> temp;
//		vec.emplace_back(move(temp));
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//			Sol({ i,j });
//	}
//
//	if (result.size() == 0)
//		cout << 1;
//	else
//	{
//		sort(result.rbegin(), result.rend());
//		cout << result[0];
//	}
//}



#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<string> vec;
int answer = 1;

void Sol(const pair<int, int>& p)
{
	int len = 1;
	
	char data = vec[p.first][p.second];
	while (1)
	{

		int dx = p.first + len;
		int dy = p.second + len;
		if (vec.size() <= dx ||  vec[0].size() <= dy )
			break;
		if (vec[dx][p.second] == data && data == vec[p.first][dy] && data == vec[dx][dy])
		{
			answer = max((len + 1) * (len + 1), answer);
		}
		len++;
	}
	
	
}
int main()
{
	vec.reserve(50);

	int n, m;
	scanf_s("%d %d", &n, &m);

	string temp;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", &temp);
		vec.emplace_back(move(temp));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			Sol({ i,j });
	}

	printf_s("%d", answer);
	
}