#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10,11 };

	auto iter = vec.begin() + 1;
	vec.erase(remove_if(vec.begin(), vec.end(), [](int n) {return n % 2 == 1; }),vec.end());
	
	for (int& num : vec)
		cout << num << "\n";
	//sort() - 5에 가까운 순서대로 정렬
	//reduce  풀어보기
	//
}