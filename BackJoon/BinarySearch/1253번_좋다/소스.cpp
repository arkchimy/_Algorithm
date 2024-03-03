#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
typedef long long ll;
int cnt;
int main()
{
	vector<ll> vec;
	int n;
	cin >> n;

	while (n--)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());

	for (auto iter = vec.begin(); iter != vec.end(); iter++)
	{
		auto left = vec.begin();
		auto right = vec.end() - 1;

		if (left == iter)
			left++;
		if (right == iter)
			right--;

		if (left == right || right < left)
			continue;

		while (1)
		{
			ll sum = *left + *right;
			if (sum < *iter)
			{
				left++;
			}
			else if (*iter < sum)
			{
				right--;
			}
			else if (*iter == sum)
			{
				cnt++;
				break;
			}
			if (left == iter)
				left++;
			if (right == iter)
				right--;

			if (left == right || right < left)
				break;
		}

	}
	cout << cnt;
}