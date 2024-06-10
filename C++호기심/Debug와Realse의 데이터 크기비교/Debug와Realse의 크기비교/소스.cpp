#include <iostream>
#include <vector>

using namespace std;
//예상
//size_t size, //4
//size_t capacity // 4
//T* start  // 4

// 결과 
// DeBug ==> 16Byte
// Release ==> 12Byte 
// 디버깅시에 필요한 데이터를 추가로 삽입함의 증명
int main()
{
	vector<int> vec;

	cout << sizeof(vec);
	
}