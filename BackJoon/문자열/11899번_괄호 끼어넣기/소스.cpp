#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<char> s;
int cnt;
void solution(char ch)
{
	if (s.empty())
	{
		if (ch == ')')
			cnt++;
		else
			s.push(ch);
	}
	else
	{
		char temp = s.top();
		if (temp == '(')
		{
			if (ch == ')')
				s.pop();
			else
				s.push(ch);
		}
	}
}
int main()
{

	string str;
	cin >> str;
	
	for_each(str.begin(), str.end(), [](char ch) { solution(ch); });

	while (!s.empty())
	{
		s.pop();
		cnt++;
	}
	printf("%d",cnt);
}