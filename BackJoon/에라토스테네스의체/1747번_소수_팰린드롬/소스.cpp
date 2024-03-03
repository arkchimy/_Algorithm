#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <algorithm>

#define SIZE 3000000
using namespace std;

typedef unsigned long long ull;

vector<ull> vec;
vector<ull> d;
void sieve()
{
	for (int i = 2; i <= SIZE; i++)
	{
		if (d[i] == 0)
			continue;
		string temp = to_string(i);
		bool chk = true;
		for (int i = 0; i <= temp.size() / 2; i++)
		{
			// 문자가 대칭되지 않을 경우
			if (temp[i] != temp[temp.size() - 1 - i])
			{
				chk = false;
				break;
			}
		}
		// 문자가 대칭된다면 vec에 추가
		if(chk)
			vec.push_back(i);

		for (int j = i * 2; j <= SIZE; j += i)
			d[j] = 0;
	}
}
void find_target(int n)
{
	auto iter = upper_bound(vec.begin(),vec.end(),n);
	if (*(iter - 1) == n)
		cout << *(--iter);
	else
		cout << *iter;

}
int main()
{
	int n;
	cin >> n;
	d.resize(SIZE + 1, 1);

	sieve();
	find_target(n);
}