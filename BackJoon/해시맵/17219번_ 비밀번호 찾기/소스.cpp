#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<string, string> h;
	
	int n, m;
	cin >> n >> m;
	pair<string, string> data;
	while (n--)
	{
		cin >> data.first >> data.second;
		h[data.first] = data.second;
	}
	string target;
	while (m--)
	{
		cin >> target;
		cout << h[target] << '\n';
	}
}