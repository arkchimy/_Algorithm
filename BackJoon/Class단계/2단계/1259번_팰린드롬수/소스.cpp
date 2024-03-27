#include <iostream>
#include <string>


using namespace std;

int main()
{
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		string str = to_string(n);
		string temp = "";
		for (auto iter = str.end() - 1; iter >= str.begin(); iter--)
		{
			temp += *iter;
			if (iter == str.begin())
				break;
		}
		if (str.compare(temp) == 0)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}