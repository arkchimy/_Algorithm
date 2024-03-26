#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string str;
	cin >> str;

	vector<int> vec(26, -1);
	for (int i = 0; i < str.size(); i++)
	{
		int idx = str[i] - 97;
		if (vec[idx] == -1)
			vec[idx] = i;
	}
	for (int idx : vec)
		cout << idx << " ";
}