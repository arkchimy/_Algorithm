#include <iostream>
#include <unordered_map>

using namespace std;

int n;

unordered_map<string, int> answer;
unordered_map<string, int> h;


int sol()
{
	int sum = 0;
	for (auto iter = answer.begin(); iter != answer.end(); iter++)
	{
		int a = iter->second;
		for (auto iter2 = iter; iter2 != answer.end(); iter2++)
		{
			if (iter == iter2) continue;
			int b = iter2->second;
			bool bChk = a < b;
			
			if (h[iter->first] < h[iter2->first] == bChk)
			{
				sum++;
			}
		}
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	cin >> n;

	for (int i = 0; i < n; i++) 
	{	
		string str;
		cin >> str;
		answer[str] = i;
	}
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		h[str] = i;
	}
	cout << sol() << "/" <<  n * (n - 1) / 2;
}