#include <iostream>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;

	cin >> n;
	while (n--)
	{
		int m;
		string str;
		cin >> m >> str;

		for (int i = 0; i < str.size(); i++) 
		{
			for (int j = 0; j < m; j++)
				cout << str[i];
		}
		cout << "\n";
	}
}