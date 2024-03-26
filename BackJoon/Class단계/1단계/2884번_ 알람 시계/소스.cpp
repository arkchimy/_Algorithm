#include <iostream>


using namespace std;

int main()
{
	int hour, min;
	cin >> hour >> min;

	if (min < 45)
	{
		hour--;
		if (hour < 0)
			hour = 23;
		min =  min + 60 - 45;
	}
	else
		min -= 45;
	cout << hour << " " << min;
}