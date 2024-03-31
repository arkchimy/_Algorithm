#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int n;
	cin >> n;

	string name[] = {"SK","CY"};
	string result = "SK";
	int i = 0;
	while(1)
	{
		result = name[i % 2];
		if (i + 1 == n || i + 3 == n)
			break;
		if (i + 7 == n )
			i += 3;
		else
			i++;
	}
	cout << result;
	
}