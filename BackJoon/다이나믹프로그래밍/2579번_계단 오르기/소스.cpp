#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	vector<int> d;
	int n;
	cin >> n;
	vec.resize(n);
	d.resize(n);

	int sum = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		cin >> n;
		vec[i] = n;
	}
	d[0] = vec[0];
	d[1] = d[0] + vec[1];
	d[2] = max(d[0] + vec[2],vec[1] + vec[2]);
	d[3] = max(d[3 - 2] +vec[3], d[3 - 3] + vec[2] + vec[3]);

	for (int i = 4; i < vec.size(); i++)
	{
		if (i == vec.size() - 2) 
		{
			d[i] = max(d[i - 2] + vec[i],d[i - 3] + vec[i - 1] + vec[i]);
		}
		else 
		{
			d[i] = max(d[i - 2] + vec[i], d[i - 3] + vec[i - 1] + vec[i]);
			d[i] = max(d[i], d[i - 4] + vec[i - 2] + vec[i]);
		}
	}
	cout << d[vec.size() - 1];
}