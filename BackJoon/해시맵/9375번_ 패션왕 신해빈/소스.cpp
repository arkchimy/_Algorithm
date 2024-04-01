#include<iostream>
#include <unordered_map>

using namespace std;

int main()
{
	

	int n, m;
	cin >> n ;

	string data;
	while (n--)
	{
		unordered_map<string, int> h;

		int sum = 1;
		cin >> m;
		while (m--)
		{
			string k,v;
			cin >> k >> v;
	
			h[v]++;
		}
		
		for (auto iter = h.begin(); iter != h.end(); iter++)
		{
			sum *= iter->second + 1;
		}

		cout << sum-1 << '\n';
	}
	

}