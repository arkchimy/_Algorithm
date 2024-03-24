#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	vector<int> vec;
	
	for(int i =0; i <9; i++)
	{
		int temp;
		cin >> temp;
		vec.emplace_back(temp);
	}
	auto iter = max_element(vec.begin(), vec.end());
	cout << *iter << "\n" << iter - vec.begin() + 1;


}