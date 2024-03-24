#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n,cnt = 1;
	cin >> n;
	while (n--)
	{
		for (int i = 0; i < n; i++)
		{
			cout << " ";
		}
		for (int i = 0; i < cnt; i++)
		{
			cout << "*";
		}
	
		cout << "\n";
		cnt++;
	}
}