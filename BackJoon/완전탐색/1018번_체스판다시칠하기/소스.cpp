#include <iostream>
#include <string>
#include <vector>


using namespace std;

string type1[8] = 
{
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
};
string type2[8] = 
{
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
};
vector<string> vec;

int main()
{
	int n, m;
	cin >> n >> m;

	vec.reserve(n);
	
	string temp;
	for(int i=0; i < n ; i++)
	{
		cin >> temp;
		vec.emplace_back(move(temp));
		
	}
	pair<int, int> start = {0,0};
	pair<int, int> end = { n - 7,m - 7 };

	int cnt = 1000;
	while (start.first != end.first && start.second != end.second)
	{
		if (n < start.first + 8)
		{
			start.first = 0;
			start.second++;
		}

		vector<int> temp(2, 0);
		int z = 0;
		for (int i = start.first; i < start.first + 8; i++)
		{
			int k = 0;
			for (int j = start.second; j < start.second + 8; j++)
			{
				if (type1[z][k] != vec[i][j])
					temp[0]++;
				if (type2[z][k] != vec[i][j])
					temp[1]++;
				k++;
			}
			z++;
			
		}
		cnt = min(cnt, min(temp[0], temp[1]));
		start.first++;
	}
	cout << cnt;

}