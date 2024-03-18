#include <iostream>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int cnt = 0;

	while (1)
	{
		if (n % 5 == 0) 
		{
			cnt += n / 5;
			break;
		}
		else 
		{
			n -= 3;
			cnt++;
		}
		if (n < 0) 
		{
			cnt = -1;
			break;
		}
	}
	cout << cnt;
}