#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> vec;
	int n;
	cin >> n;
	while (n--)
	{
		int temp;
		cin >> temp;

		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());

	int result = 0;
	int cost = 0;
	for_each(vec.begin(), vec.end(), [&result, &cost](int val) 
		{
			result += cost + val;
			cost += val;
		}
	);
	cout << result;
}