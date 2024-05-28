#include <iostream>


using namespace std;


template <typename T>
struct List
{
	List* left;
	List* right;
	T data;

};

typedef List<int> iList;

template<typename T>
void insert(List<T>** head, T data)
{

	List<T>* header =  *head;
	if (header == nullptr)
	{
		header = new List<T>();
		header->data = data;
		*head = header;
		return;
	}
	if (header->data <= data)
	{
		insert(&header->right, data);
	}
	else
		insert(&header->left, data);
}


template <typename T>
void midsearch(List<T>* header)
{
	if (header == nullptr)
		return;
	midsearch(header->left);
	cout << header->data << " , ";
	midsearch(header->right);

}
template <typename T>
void dealloc(List<T>* header)
{

	if (header == nullptr)
	{
		return;
	}
	
	dealloc(header->left);
	dealloc(header->right);
	delete header;
}
int main()
{
	iList* header = nullptr;

	for (int i = 0; i < 100; i++)
		insert(&header, rand() % 101);
	midsearch(header);
	dealloc(header);


}