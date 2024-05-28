#include <iostream>
#include <vector>
#include <list>

#define SIZE 11
using namespace std;

// 고정적으로 O(n^2)  
// stable 하다.
// in_place하다.

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

// 시간복잡도 O(n^2)
// in_place 하다.
// stable 하다.

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
// 시간복잡도 정렬이 되어있는경우 N번이다. 
// N번을 해야하는데 정렬이되어있는경우 1번 연산으로 끝남.
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
			
			if(vec[j] > val) // 값이 큰걸 발견했을때 떙긴다.
				vec[j + 1] = vec[j]; 
			else // 작은값을 발견하면  
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

// pivot 을정할떄 중간으로 정하잖아요? 
// 정렬되도 nlogn   => n^2 
// pivot 파티션을 나누었을떄 한쪽 파티션의 크기가 0될경우가 계속된다면 n^2
// nLogN
// in_place 하다.
// stable 안하다.

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

	//n^2  = 데이터가 10만 
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