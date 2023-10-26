#include <iostream>
#include <algorithm>
#include <vector>
#include "MyPrint.h"
using namespace std;

				/*  bool equal (iterator )
				* equal  ���� bool Ÿ���� ��ȯ�ϸ�  ������ �����ؼ� �� ������ �������� return �ϴ� �Լ��̴�.
				*/
				/*
				*    fill  ���� iterator �� ������ �ְ� �ش� �κ��� val ������ �ٲ��ִ� �Լ��̴�.
				*/
int main()
{
	int arr1[] = { 0,1,2,3,4,5,6,7,8,9 };
	int arr2[] = { 8,7,3,3,4,5,7,7,8,9 };

	vector<int> v1(&arr1[0], &arr1[10]);
	vector<int> v2(&arr2[0], & arr2[10]);

	bool is_equal = equal(v1.begin() + 3, v1.begin() + 5, v2.begin() + 3);
	if (is_equal)
		cout << "�� ������ ������ �����ϴ�!" << endl;
	fill(v1.begin(),v1.begin()+ 4, 0);
	Print(v1, "v1�� �����Դϴ�.");

	reverse(v1.begin(), v1.end());
	Print(v1, "v1�� �������Դϴ�.");

	copy(v1.begin(), v1.end(), v2.begin());
	Print(v2, "v1�� ������ v2�Դϴ�.");

	reverse(v1.begin(), v1.end());
	vector<int>::iterator iter = remove(v1.begin(), v1.end(), 4);
	Print(v1,"4�� ������ ���  iter�� �մ�� ����̴� ���� ������ �κ��� ���簡�Ǿ���.");

	v1.erase(iter,v1.end());
	Print(v1, "iter�� ������ ������ ���");
	return 0;
}