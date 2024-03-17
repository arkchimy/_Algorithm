#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int result = 0;
	string g_data;
	cin >> g_data;
	bool chk = false;
	vector<int> vec;
	vec.reserve(g_data.size());
	for (int i = 0; i < g_data.size(); i++)
		vec.emplace_back(g_data[i] - '0');
	sort(vec.rbegin(), vec.rend());
	sort(g_data.rbegin(), g_data.rend());
	for_each(vec.begin(), vec.end(), [&result,&chk](int ch)
		{
			if (ch == 0)
				chk = true;
			result += ch;
		});
	if (result % 3 != 0 || !chk)
		cout << "-1";
	else
		cout << g_data;
	return 0;
}

