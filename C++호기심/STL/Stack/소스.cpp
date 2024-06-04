#include <iostream>

using namespace std;

template<typename T>
struct Node
{
	Node<T>* front;
	T data;
};

template<typename T>
struct Stack
{
	Stack()
		:node(nullptr) {};
	~Stack()
	{
		Dealloc();
	}
	Node<T>* node;

	void Push(T input)
	{
		if (node == nullptr)
		{
			node = (Node<T> *)malloc(sizeof(Node<T>));
			node->front = nullptr;
			node->data = input;
			return;
		}

		Node<T>* temp = (Node<T> *)malloc(sizeof(Node<T>));
		temp->data = input;
		temp->front = node;
		node = temp;
	}
	void Print()
	{
		Node<T>* temp = node;
		while (temp != nullptr)
		{
			cout << temp->data <<"\n";
			Node<T>* front = temp->front;
			temp = front;
		}
		
	}
	void Dealloc()
	{
		while (node != nullptr)
		{
			Node<T>* front = node->front;
			free(node);
			node = front;
		}
	}
};


int main()
{
	Stack<int> s;
	
	for (int i = 0; i < 10; i++)
		s.Push(i);
	s.Print();
}