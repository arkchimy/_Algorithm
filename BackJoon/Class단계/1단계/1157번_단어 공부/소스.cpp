#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<char,int> m;

int main()
{
	string str;
	vector<char> vec;
	getline(cin, str);
	vec.reserve(str.size());

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
			continue;
		char data = toupper(str[i]);
		if (m.find(data) == m.end()) 
		{
			m[toupper(data)] = 1;
			vec.push_back(toupper(data));
		}
		else
		{
			m[data]++;
		}
	}
	int max = 0;
	char result;
	bool bChk = true;
	for (int i = 0; i < vec.size(); i++)
	{
		if (m[vec[i]] == max)
		{
			bChk = false;
		}
		else if(m[vec[i]] > max)
		{
			max = m[vec[i]];
			result = vec[i];
			bChk = true;
		}
	}

	if (!bChk)
		cout << '?';
	else
		cout << result;

}