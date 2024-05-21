#include <iostream>

using namespace std;


template<typename T>
struct List
{
	List* operator ++ () { return next; }

	List<T>* next;
	T data;
};

template<typename T>
void Print(List<T>* head)
{
	List<T>* current = head;

	while (current != nullptr)
	{
		cout << current->data <<"\n";
		current = current->next;
	}
}
template<typename T>
List<T>* reverse(List<T>& head)
{
	List<T>* current = &head;
	List<T>* front = nullptr;
	List<T>* pre = nullptr;

	while (current != nullptr)
	{
		pre = current->next;
		current->next = front;
		front = current;

		current = pre;

	}
	return front;
}


int main()
{
	List<int>* list = new List<int>();
	List<int>* current = list;

	for (int i = 1; i <= 10; i++)
	{
		current->data = i;
		if (i < 10)
			current->next = new List<int>();
		else
			current->next = nullptr;
		current = ++(*current);
	}

	Print(list);
	Print(reverse(*list));
	
	while (list != nullptr)
	{
		auto temp = list;
		list = ++(*list);

		delete temp;

	}
}