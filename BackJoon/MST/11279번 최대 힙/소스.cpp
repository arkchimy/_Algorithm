#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	
	while (n--)
	{
		int temp;
		cin >> temp;
		if (!temp)
		{
			if (q.empty())
				cout << 0 << '\n';
			else
			{
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else
			q.push(temp);
	}

}