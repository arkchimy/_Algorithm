#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int> q; 

	int n;
	cin >> n;

	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp; // 100  10   20  
		q.push(-temp); //  -100 -10 -20 �⺻�� �ִ���
	}
	

	while (!q.empty())
	{
		cout << -q.top() << '\n';
		q.pop();
	}
}


//
//
//struct Student
//{
//	int score[10000];
//};
////24 mapping
//vector<int> nums;// heap �ּ� 4����Ʈ + 4 + 4 = 12byte
//
//std::array<int, 1000000> arr; // 2   
//int arr2[1000000]; // 1
//
//int main()
//{
//
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int n;
//	cin >> n;
//	int* nptr =  new int();
//	nums.resize(1000000); // ù���� � ���鲨��
//	
//	cout << sizeof(nums) << endl;
//	cout << sizeof(arr) << endl;
//	cout << sizeof(arr2) << endl;
//
//	while (n--)
//	{
//		nums.emplace_back(move(n));//copy 0
//	}
//	sort(nums.begin(), nums.end());
//
//	for (const int& num : nums) // copy ?  ���簡 ���Ϸ�����...
//	{
//		cout << num << '\n';
//	}
//
//}


