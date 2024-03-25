#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long n, m;
	cin >> n >> m;
	vector<long long> vec;

	while (n--)
	{
		long long temp;
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end());
	long long stick = *max_element(vec.begin(), vec.end());
	long long sum = 0;

	while (1)
	{
		if (binary_search(vec.begin(), vec.end(), stick))
		{
			sum -= count(vec.begin(), vec.end(), stick);
		}
		sum += vec.end() - lower_bound(vec.begin(), vec.end(), stick);
		if (sum >= m)
			break;
		stick--;
	}

	cout << stick;

}