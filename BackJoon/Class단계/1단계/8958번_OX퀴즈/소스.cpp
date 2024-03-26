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
		string str;
		cin >> str;
		int sum = 0;
		int score = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'O')
			{
				score += sum + 1;
				sum++;
			}
			else
				sum = 0;
		}
		cout << score << "\n";
	}
}