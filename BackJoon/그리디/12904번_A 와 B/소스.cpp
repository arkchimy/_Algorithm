#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

bool bChk = false;

void sol(string& str,string& t)
{
	if (t[t.size() - 1] == 'A')
	{
		t = t.substr(0, t.size() - 1);
	}
	else
	{
		t = t.substr(0, t.size() - 1);
		stack<char> s;
		for (int i = 0; i < t.size(); i++)
			s.push(t[i]);
		while(!s.empty())
	}
}


int main()
{
	string s, t;
	cin >> s >> t;
	sol(s,t);

	if (!bChk)
		cout << 0;
	else
		cout << 1;
}