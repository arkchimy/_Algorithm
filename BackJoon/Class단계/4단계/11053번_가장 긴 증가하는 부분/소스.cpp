#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> vec(n);
	vector<int> dp(n);


	for(int i =0; i < n ; i++)
	{
		cin >> vec[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		int len = 1;
		auto iter = vec.begin();
		while (1)
		{
			iter = find_if(iter, vec.begin() + i, [&vec, i](const int& val) {return vec[i] > val; });
			if (iter == vec.begin() + i)
				break;
			int idx = distance(vec.begin(), iter);
			len = max(dp[idx] + 1, len);
			iter++;
		}
		dp[i] = len;
		
	}
	cout << *max_element(dp.begin(), dp.end());

}