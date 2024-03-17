#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;


stack<char> s2;
string ReverseStr()
{
	string temp = "";
	while (!s2.empty())
	{
		temp += s2.top();
		s2.pop();
	}
	return temp;
}
int main()
{
	string str;
	getline(cin, str);
	int idx = 0 , current = 0;
	
	stack<char> s;
	
	string result = "";
	for(int i =0; i < str.size();i++)
	{
		if (str[i] == '<')
		{
			result += ReverseStr();
			s.push('<');
		}

		if (s.empty())
		{
			if (str[i] == ' ')
				result += ReverseStr() + ' ';
			else
				s2.push(str[i]);
		}
		else
			result += str[i];

		if (str[i] == '>')
		{
			s.pop();
		}
		
	}
	result += ReverseStr();
	cout << result;
}