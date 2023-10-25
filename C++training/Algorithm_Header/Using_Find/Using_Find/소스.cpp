#include <iostream>
#include "MyPrint.h"

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool Fruit_chk(string data)
{	// myprint���ٰ� �����ߴ��� ������
	if (data.find("��") != string::npos)
		return true;
	return false;
}

int main()
{
	string arr[] = { "����","��","���" ,"����"};
	vector<string> v(&arr[0],&arr[4]); //  iter�� ���� v.end()ó�� �� �κ��� ��Ȯ�� ��������� &arr[5]�� �ߴ��� ��������.

	Print(v);

	// find(iterator begin, iterator end, const & val ) 
	vector<string>::iterator it = find(v.begin(), v.end(), "����");
	if (it != v.end()) // ã��
		cout << distance(v.begin(), it) << "�ε����� ����"<< endl; // 3�ε��� ��ȯ ����
	// find_if(iterator begin, iterator end, bool (*Func_name) )   

	vector<string>::iterator iter = find_if(v.begin(), v.end(), Fruit_chk);
	cout << distance(v.begin(), iter) << "�ε����� ����"; // 3�ε��� ��ȯ ����
	return 0;
}
/*
	find_if(iterator begin, iterator end, bool(*Func_name))
	when : �Լ� �����ͷ� �޾Ƽ� �� ���ǿ� �´� iter�� ��ȯ�ϴ� �Լ� ������  �ϳ��� �����ҋ� �����������̴�.
* */

/*
	find(iterator begin, iterator end, const & val ) 
	when : val�� �ش��ϴ� ���� ã������� ����Ҽ��ִ�. iter�� ��ȯ�Ѵ�.
* */

/*
	distance(iterator begin, iterator  end)
	when : iter�� ������ �ε����� ��ȯ �ް������ ����Ѵ�. 
* */


