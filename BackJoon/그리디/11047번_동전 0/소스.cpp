#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int main()
{
	int n, k;
	cin >> n >> k;

	int temp;
	int cnt = 0;

	while (n--)
	{
		cin >> temp;
		dq.push_front(temp);
	}
	while (k != 0)
	{
		temp = dq.front();
		dq.pop_front();
		if (k >= temp)
		{
			 cnt +=  k/temp;
			 k %= temp;
		}
	}
	cout << cnt;

}