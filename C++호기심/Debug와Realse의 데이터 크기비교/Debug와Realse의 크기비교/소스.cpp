#include <iostream>
#include <vector>

using namespace std;
//����
//size_t size, //4
//size_t capacity // 4
//T* start  // 4

// ��� 
// DeBug ==> 16Byte
// Release ==> 12Byte 
// �����ÿ� �ʿ��� �����͸� �߰��� �������� ����
int main()
{
	vector<int> vec;

	cout << sizeof(vec);
	
}