#include <iostream>
#include <deque>
#include <algorithm>

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
		deque<pair<int, int>> dq;
		int len,target;
		cin >> len >> target;
		for (int i = 0; i < len; i++) 
		{
			int temp;
			cin >> temp;
			dq.push_back({ temp,i });
	
		}
		int cnt = 0;

		while (!dq.empty())
		{
			pair<int,int> front = dq.front();
			pair<int,int> max = *max_element(dq.begin(), dq.end());
			dq.pop_front();
			
			if (front.first != max.first)
				dq.push_back(front);
			else if (front.second == target)
			{
				cnt++;
				break;
			}
			else
				cnt++;
			
		}
		cout << cnt << '\n';
	}
}