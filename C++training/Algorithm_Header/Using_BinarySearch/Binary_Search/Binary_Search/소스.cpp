#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int target = 2020; //목표
	deque<int> data;
	for (int i = 0; i < 10000; i++)
	{
		if (i == 0)
		{
			data.push_back(i);
			continue;
		}
		if (i > 2000 && i < 2050)
			continue;
		data.push_back(i);
		data.push_front(i); 
		// {3210123} 이런식으로 나옴
	}
	sort(data.begin(), data.end());
	bool chk  = binary_search(data.begin(), data.end(), target); //이진탐색으로 굉장히 빠름 단지 정렬되어있어야한다는 조건이있음.
	if (!chk) 
	{
		cout << "값이 없습니다" << endl;
		deque<int>::iterator iter = lower_bound(data.begin(), data.end(), target);
		data.insert(iter, target);
		iter = lower_bound(data.begin(), data.end(), target);
		cout << *iter;
		
	}
	else 
	{
		cout << "값이 존재합니다!!!" << endl;
		deque<int>::iterator iter = lower_bound(data.begin(), data.end(), target);
		cout << distance(data.begin(), iter) << " <=  target이면서 가장 낮은 인덱스 " << *iter << endl;
		iter = upper_bound(data.begin(), data.end(), target);
		cout << distance(data.begin(), iter) << "<= target이면서 가장 높은 인덱스" <<  *iter <<endl;
		
	}
	return 0;
}
/*
* lower_bound()  는 target에 해당하는 첫번째 실제 iter를 반환한다
* upper_bound() 는 iter의 end처럼 iter가 가지고있는 값은 target이 아니게 되지만 바로 다음 iter를 가리키게된다.
* 
why :  <왜 이런 함수를 사용하게 되었는가>  
		일단 이 알고리즘은 정렬된 컨테이너에게만 사용이 가능하다는 점이다.
		정렬이 되었다면 같은 수가 연속적으로 출현할 것 이다.

when :	정렬된 데이터에서 삽입할수도 혹은 제거하는 경우 

How :	erase(lower_bound(),upper_bound);사용에 적합하다.
		lower_bound는 삽입연산을 할떄 삽입가능한 iter를 반환해주기때문에 편하다.
How :	insert(lower_bound,val);
*/