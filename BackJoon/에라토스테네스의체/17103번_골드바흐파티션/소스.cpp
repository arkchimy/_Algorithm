#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define SIZE 1000001

using namespace std;

vector<int> vec;
vector<int> prime;
void seive()
{
	for (int i = 2; i < SIZE; i++)
	{
		if (vec[i] == false)
			continue;
		prime.push_back(i);
		for (int k = i * 2; k < SIZE; k += i)
			vec[k] = 0;
	}
}
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vec.resize(SIZE, 1);
	vec[0] = 0;
	vec[1] = 0;
	seive();

	int n;
	vector<int> result;
	cin >> n;
	while (n--)
	{
		int num,cnt = 0;
		cin >> num;
		// num 보다 큰 수중 가장작은 수를 가져옴
		auto iter = upper_bound(prime.begin(), prime.end(), num);
		
		int a, b;

		while (1)
		{
			iter--;
			a = *iter;
			b = num - a;
			if (a < b) break;
			if (binary_search(prime.begin(), prime.end(), b))
			{
				cnt++;
			}
			if (iter == prime.begin())
				break;
			
		}
		result.push_back(cnt);
	}
	for (int data : result)
		cout << data << "\n";
}