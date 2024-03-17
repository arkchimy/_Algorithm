#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s, t;

	while (cin >> s >> t)
	{
		auto iter = t.begin();
		bool bchk = true;
		for (int i = 0; i < s.size(); i++)
		{
			iter = find(iter, t.end(), s[i]);
			if (iter == t.end())
			{
				bchk = false;
				break;
			}
			iter++;
		}
		if (bchk)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

}