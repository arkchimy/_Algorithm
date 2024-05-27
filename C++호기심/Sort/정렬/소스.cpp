#include <iostream>
#include <vector>

#define SIZE 101
using namespace std;


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
void insert_sort(vector<int> vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		int idx = i;
		int val = vec[i];

		for (int j = i - 1; j >= 0; j--)
		{
			
			if(vec[j] > val)
				vec[j + 1] = vec[j]; //  0 1 2 3   val = 0 
			else
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
			if (vec[left] >= vec[end]) 
				break;
		}
		
		for (; right >= start; right--)
		{
			if (vec[right] <= vec[end])
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
}