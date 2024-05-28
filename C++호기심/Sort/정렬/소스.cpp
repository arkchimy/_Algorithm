#include <iostream>
#include <vector>
#include <list>

#define SIZE 11
using namespace std;

// ���������� O(n^2)  
// stable �ϴ�.
// in_place�ϴ�.

void bubble_sort(vector<int> vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
	{
		for (int j = 0 ; j < vec.size() - i - 1; j++)
		{
			if (vec[j] > vec[j + 1])
				swap(vec[j], vec[j + 1]);
		}
	}
	cout << "Bubble_Sort  : ";
	for (int val : vec)
		cout << val << ", ";
	cout << "\n";
}

// �ð����⵵ O(n^2)
// in_place �ϴ�.
// stable �ϴ�.

void select_sort(vector<int> vec)
{
	int val = 0;
	int idx = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		val = vec[i];
		idx = i;
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (val > vec[j])
			{
				val = vec[j];
				idx = j;
			}
		}
		if (i != idx)
		{
			swap(vec[i], vec[idx]);
		}
	}
	cout << "Select_Sort  : ";
	for (int val : vec)
		cout << val << ", ";
	cout << "\n";
}
// �ð����⵵ ������ �Ǿ��ִ°�� N���̴�. 
// N���� �ؾ��ϴµ� �����̵Ǿ��ִ°�� 1�� �������� ����.
// Stable 
// in_place 

void insert_sort(vector<int> vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		int idx = i;
		int val = vec[i];

		for (int j = i - 1; j >= 0; j--)
		{
			
			if(vec[j] > val) // ���� ū�� �߰������� �����.
				vec[j + 1] = vec[j]; 
			else // �������� �߰��ϸ�  
			{
				vec[j + 1] = val;
				break;
			}
			if (j == 0)
			{
				vec[j] = val;
			}
		}
		
	}

	cout << "insert_Sort  : ";
	for (int val : vec)
		cout << val << ", ";
	cout << "\n";
}

// pivot �����ҋ� �߰����� �����ݾƿ�? 
// ���ĵǵ� nlogn   => n^2 
// pivot ��Ƽ���� ���������� ���� ��Ƽ���� ũ�Ⱑ 0�ɰ�찡 ��ӵȴٸ� n^2
// nLogN
// in_place �ϴ�.
// stable ���ϴ�.

void Quick_sort(vector<int>& vec,int start, int end)
{
	if (start >= end)
		return;
	int p = (start + end) / 2;
	swap(vec[end], vec[p]);

	
	int left = start, right = end - 1;

	while (1)
	{
		for(; left < end; left++)
		{
			if (vec[left] > vec[end]) 
				break;
		}
		
		for (; right >= start; right--)
		{
			if (vec[right] < vec[end])
				break;
		}
		if (left <= right)
		{
			swap(vec[left], vec[right]);
			left++;
			right--;
		}
		else
		{
			swap(vec[left], vec[end]);
			break;
		}
	} 

	Quick_sort(vec, start, left - 1);
	Quick_sort(vec, left + 1, end);

}

list<int> Merge(list<int>& left, list<int>& right)
{
	list<int>::iterator iter = left.begin();
	list<int>::iterator iter2 = right.begin();

	list<int> result;
	while (iter != left.end() && iter2 != right.end())
	{
		result.push_back(min(*iter, *iter2));
		if (*iter <= *iter2)
			iter++;
		else
			iter2++;
	}
	while (iter != left.end())
	{
		result.push_back(*iter);
		iter++;
	}
	while (iter2 != right.end())
	{
		result.push_back(*iter2);
		iter2++;
	}
	return result;

}

list<int> Merge_sort(vector<int>& vec, int start, int end)
{
	if (start == end)
		return list<int>() = { vec[start] };


	int mid = (start + end) / 2;
	list<int> left = Merge_sort(vec, start, mid);
	list<int> right = Merge_sort(vec, mid + 1, end);
	
	return Merge(left,right);
	
}


int main()
{
	vector<int> vec;
	vec.resize(SIZE);

	for (int i = 0; i < SIZE; i++)
		vec[i] = rand() % 101;

	//n^2  = �����Ͱ� 10�� 
	cout << "start \n";
	bubble_sort(vec);
	select_sort(vec);
	insert_sort(vec);
	Quick_sort(vec, 0, vec.size() - 1);

	cout << "Quick_sort  : ";
	for (int val : vec)
		cout << val << ", ";
	cout << "\n";

	for (int i = 0; i < SIZE; i++)
		vec[i] = rand() % 101;
	list<int> result = Merge_sort(vec, 0, vec.size() - 1);

	cout << "Merge_sort  : ";
	for (int val : result)
		cout << val << ", ";
	cout << "\n";
}