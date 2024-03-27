#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<string> vec;
	vec.reserve(10001);
	vec.emplace_back("0");
	int num = 666;
	while (vec.size() != n + 1)
	{
		string str = to_string(num);
		if(str.find("666") != string::npos)
			vec.emplace_back(str);
		num++;
	}
	cout << vec[n];
}