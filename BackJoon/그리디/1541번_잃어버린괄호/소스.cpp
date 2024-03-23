#include <iostream>
#include <string>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int result= 0;

	string str,temp="";
	cin >> str;
	bool bPlus = true;

	for (int i = 0; i < str.size(); i++)
	{
		if (bPlus)
		{
			if (str[i] == '-')
			{
				bPlus = false;
				result += stoi(temp);
				temp = "";
			}
			else if (str[i] == '+')
			{
				result += stoi(temp);
				temp = "";
			}
			else
				temp += str[i];
		}
		else
		{
			if (str[i] == '-')
			{
				result -= stoi(temp);
				temp = "";
			}
			else if (str[i] == '+')
			{
				result -= stoi(temp);
				temp = "";
			}
			else
				temp += str[i];
		}
		
	}
	if(bPlus)
		result += stoi(temp);
	else
		result -= stoi(temp);
	cout << result;
}