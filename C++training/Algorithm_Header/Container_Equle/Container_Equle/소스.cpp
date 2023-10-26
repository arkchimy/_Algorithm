#include <iostream>
#include <algorithm>
#include <vector>
#include "MyPrint.h"
using namespace std;

				/*  bool equal (iterator )
				* equal  문은 bool 타입을 반환하며  범위를 지정해서 그 범위지 같은지를 return 하는 함수이다.
				*/
				/*
				*    fill  문은 iterator 의 범위를 주고 해당 부분을 val 값으로 바꿔주는 함수이다.
				*/
int main()
{
	int arr1[] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr2[] = { 8,7,3,3,4,5,7,7,8,9 };

	vector<int> v1(&arr1[0], &arr1[10]);
	vector<int> v2(&arr2[0], & arr2[10]);

	bool is_equal = equal(v1.begin() + 3, v1.begin() + 5, v2.begin() + 3);
	if (is_equal)
		cout << "두 백터의 범위는 같습니다!" << endl;
	fill(v1.begin(),v1.begin()+ 4, 0);
	Print(v1, "v1의 벡터입니다.");

	reverse(v1.begin(), v1.end());
	Print(v1, "v1의 리버스입니다.");

	copy(v1.begin(), v1.end(), v2.begin());
	Print(v2, "v1을 복사한 v2입니다.");

	reverse(v1.begin(), v1.end());
	vector<int>::iterator iter = remove(v1.begin(), v1.end(), 4);
	Print(v1,"4를 삭제한 모습  iter를 앞당긴 모습이다 단지 마지막 부분이 복사가되었다.");

	v1.erase(iter,v1.end());
	Print(v1, "iter를 제거한 벡터의 모습");
	return 0;
}