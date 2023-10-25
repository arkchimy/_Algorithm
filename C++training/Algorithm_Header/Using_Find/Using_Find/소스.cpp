#include <iostream>
#include "MyPrint.h"

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool Fruit_chk(string data)
{	// myprint에다가 선언했더니 에러남
	if (data.find("박") != string::npos)
		return true;
	return false;
}

int main()
{
	string arr[] = { "감자","배","사과" ,"수박"};
	vector<string> v(&arr[0],&arr[4]); //  iter의 개념 v.end()처럼 끝 부분을 정확히 적어줘야함 &arr[5]로 했더니 에러났음.

	Print(v);

	// find(iterator begin, iterator end, const & val ) 
	vector<string>::iterator it = find(v.begin(), v.end(), "수박");
	if (it != v.end()) // 찾음
		cout << distance(v.begin(), it) << "인덱스에 존재"<< endl; // 3인덱스 반환 예상
	// find_if(iterator begin, iterator end, bool (*Func_name) )   

	vector<string>::iterator iter = find_if(v.begin(), v.end(), Fruit_chk);
	cout << distance(v.begin(), iter) << "인덱스에 존재"; // 3인덱스 반환 예상
	return 0;
}
/*
	find_if(iterator begin, iterator end, bool(*Func_name))
	when : 함수 포인터로 받아서 그 조건에 맞는 iter를 반환하는 함수 조건이  하나로 부족할떄 쓸모있을것이다.
* */

/*
	find(iterator begin, iterator end, const & val ) 
	when : val에 해당하는 값을 찾고싶을떄 사용할수있다. iter를 반환한다.
* */

/*
	distance(iterator begin, iterator  end)
	when : iter를 가지고 인덱스를 반환 받고싶을때 사용한다. 
* */


