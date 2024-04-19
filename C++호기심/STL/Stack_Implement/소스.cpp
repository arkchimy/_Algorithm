#include <iostream>

#define SIZE 10
template<typename T>
struct Stack
{
	Stack()
	{
		data = new T[SIZE];
	}
	bool IsFull()
	{
		return top + 1 == SIZE;
	}
	bool IsEmpty()
	{
		return top == -1;
	}
	void push(T input)
	{
		if (IsFull())
		{
			T* newArr = new T[size * 2];
			int* arr = new int[20];
			
			for (int i = 0; i < size; i++)
			{
				newArr[i] = data[i];
				//*(newArr + i) = *(data + i);
			}
			delete[] data;
			
			data = newArr;
			size = size * 2;
		}
		top++;//0
		*(data + top)  = input;
	}
	void pop()
	{
		if (IsEmpty())
		{
			std::cout << " IsEmpty \n";
			return;
		}
		top--;
	}
	T Top()
	{
		return *(data + top);
	}
	int top = -1;
	int size = SIZE;
	T* data;
};

typedef Stack<int> IStack;
int main()
{
	IStack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);
	s.push(10);
	s.push(11);
	s.push(12);

	while (!s.IsEmpty())
	{
		int num = s.Top();
		s.pop();
		std::cout << num << "\n";
	}
}