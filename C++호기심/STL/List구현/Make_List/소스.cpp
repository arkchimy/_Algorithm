#include <iostream>


using namespace std;

template<typename T>
struct List
{
	List<T>()
		:data(0), next(nullptr)
	{

	};
	List* next;
	T data;
};

typedef List<int> iList;


template<typename T>
void print(List<T>* head)
{
	List<T>* current = head;

	while (current != nullptr)
	{
		cout << current->data << "\n";
		current = current->next;

	}
}

template<typename T>
List<T>* reverse(List<T>* head)
{
	List<T>* current = head;
	List<T>* temp = new List<int>();
	List<T>* front = nullptr;
	while (current != nullptr)
	{
		temp = current->next;
		temp->data = current->next->data;
		temp->next = front;

		front = temp;
		current = current->next;
	}
	
	return temp;
};


int main()
{
	
	iList* list = new iList();
	iList* head = list;

	for (int i = 0; i < 5; i++)
	{
		list->data = i;
		list->next = new iList();
		
		list = list->next;
	}

	
	print<int>(head);
	head = reverse<int>(head);
	print<int>(head);


}