#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int target = 2020; //��ǥ
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
		// {3210123} �̷������� ����
	}
	sort(data.begin(), data.end());
	bool chk  = binary_search(data.begin(), data.end(), target); //����Ž������ ������ ���� ���� ���ĵǾ��־���Ѵٴ� ����������.
	if (!chk) 
	{
		cout << "���� �����ϴ�" << endl;
		deque<int>::iterator iter = lower_bound(data.begin(), data.end(), target);
		data.insert(iter, target);
		iter = lower_bound(data.begin(), data.end(), target);
		cout << *iter;
		
	}
	else 
	{
		cout << "���� �����մϴ�!!!" << endl;
		deque<int>::iterator iter = lower_bound(data.begin(), data.end(), target);
		cout << distance(data.begin(), iter) << " <=  target�̸鼭 ���� ���� �ε��� " << *iter << endl;
		iter = upper_bound(data.begin(), data.end(), target);
		cout << distance(data.begin(), iter) << "<= target�̸鼭 ���� ���� �ε���" <<  *iter <<endl;
		
	}
	return 0;
}
/*
* lower_bound()  �� target�� �ش��ϴ� ù��° ���� iter�� ��ȯ�Ѵ�
* upper_bound() �� iter�� endó�� iter�� �������ִ� ���� target�� �ƴϰ� ������ �ٷ� ���� iter�� ����Ű�Եȴ�.
* 
why :  <�� �̷� �Լ��� ����ϰ� �Ǿ��°�>  
		�ϴ� �� �˰����� ���ĵ� �����̳ʿ��Ը� ����� �����ϴٴ� ���̴�.
		������ �Ǿ��ٸ� ���� ���� ���������� ������ �� �̴�.

when :	���ĵ� �����Ϳ��� �����Ҽ��� Ȥ�� �����ϴ� ��� 

How :	erase(lower_bound(),upper_bound);��뿡 �����ϴ�.
		lower_bound�� ���Կ����� �ҋ� ���԰����� iter�� ��ȯ���ֱ⶧���� ���ϴ�.
How :	insert(lower_bound,val);
*/