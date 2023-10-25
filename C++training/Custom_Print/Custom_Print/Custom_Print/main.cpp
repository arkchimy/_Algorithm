#include <iostream>
#include "MyPrint.h"

#include <vector>
#include <deque>
using namespace std;

int main(void)
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	deque<int> dv;
	for (int i = 1; i <= 5; i++)
	{
		dv.push_back(i);
		dv.push_front(i);
	}
	Print(v, "벡터 컨테이너");
	Print(dv, "데크 컨테이너");

	return 0;
}