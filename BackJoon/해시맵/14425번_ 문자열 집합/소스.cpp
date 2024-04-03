#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int result = 0;
	unordered_map<string, int> h;
	while (n--)
	{
		string data;
		cin >> data;
		h[data]++;// 1
	}
	while (m--)
	{
		string data;
		cin >> data;
		if (h.find(data) != h.end())
			result++;
	}
	cout << result;
}