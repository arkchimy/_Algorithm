#include <iostream>

using namespace std;


int main()
{
	int n;
	cin >> n;
	bool bChk = false;
	if (n == 1 || n == 8)
		bChk = true;

	if (!bChk) 
	{
		cout << "mixed";
		return 0;
	}
	if (n == 1)
	{
		while (n != 8)
		{
			n++;
			int temp;
			cin >> temp;
			if (temp != n) 
			{
				cout << "mixed";
				return 0;
			}
		}
		cout << "ascending";
	}
	else
	{
		while (n != 1)
		{
			n--;
			int temp;
			cin >> temp;
			if (temp != n)
			{
				cout << "mixed";
				return 0;
			}
		}
		cout << "descending";
	}
}