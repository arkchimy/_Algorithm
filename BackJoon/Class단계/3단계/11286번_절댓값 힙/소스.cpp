#include <iostream>
#include <algorithm>
#include <vector>

#include <queue>

using namespace std;

bool Comp(const int& a, const int& b)
{
	if (abs(a) == abs(b))
		return a > b;
	return abs(a) > abs(b);
}
int main()
{
	auto comp = [](int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		return abs(a) > abs(b);
	};
	bool (*compptr)(const int&, const int&)= Comp;
	auto compptr2 = Comp;

	priority_queue<int, vector<int>, decltype(comp)> q(comp);
	priority_queue<int, vector<int>, decltype(compptr)> cx(compptr);
	priority_queue<int, vector<int>, decltype(compptr2)> cz(compptr2);

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
				int top = q.top();
				q.pop();
				cout << top << '\n';
			}
		}
		else
		{
			q.push(temp);
		}
	}
	
}

