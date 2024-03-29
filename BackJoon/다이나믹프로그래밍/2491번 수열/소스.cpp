#include <iostream>
#include <vector>
using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> vec;
	vec.resize(n);

	int min_len = 1;
	int max_len = 1;

	for(int i =0; i < n; i++)
	{
		cin >> vec[i];
	}
	int result = 0;
	for (int i = 1; i < n ; i++)
	{
		if (vec[i - 1] == vec[i])
		{
			max_len++;
			min_len++;
		}
		else if (vec[i - 1] < vec[i])
		{
			max_len++;
			result = max(result, min_len);
			min_len = 1;
		}
		else if (vec[i - 1] > vec[i])
		{
			min_len++;
			result = max(result, max_len);
			max_len = 1;
		}
		
	}
	result = max(result, max(min_len, max_len));
	cout << result;

}