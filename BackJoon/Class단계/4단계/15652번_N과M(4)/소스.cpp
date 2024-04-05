#include<iostream>
#include <string>

using namespace std;


int n, m;

void sol(int idx,int level, string str)
{

	if (level == m)
	{
		cout << str << "\n";
		return;
	}

	
	for (int k = idx; k <= n; k++)
		sol(k, level + 1, str + " " + to_string(k));

}
int main()
{
	
	cin >> n >> m;
		
	for (int k = 1; k <= n; k++)
	{
		string str = "";
		sol(k,1, str + to_string(k));
	}
	
}