#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	n = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		n += str[i] - '0';
	}
	cout << n;
}