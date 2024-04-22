#include <iostream>
#include <string>

template <typename T>
class Vector
{
public:
	Vector()
		:mSize(0),capacity(2)
	{
		data = new T[capacity];
	}
	~Vector()
	{
		delete[] data;
	}
	Vector(Vector&& other) noexcept
		:mSize(move(other.mSize)),capacity(std::move(other.capacity))
	{
		other.data = nullptr;
	}
	T& operator [] (const int idx)
	{
		return data[idx];
	}
	void extend()
	{
		T* temp = new int[capacity * 2];
		// 앞의 인덱스부터 하면 안될 것같지만 실험
		for (int i = 0 ; i < mSize; i++)
		{
			temp[i] = std::move(data[i]); 
		}

		data = std::move(temp);
		capacity *= 2;
	}
	bool IsFull()
	{
		return mSize == capacity;
	}
	bool IsEmpty()
	{
		return mSize == 0;
	}
	void push_back(const T& arg)
	{
		if (IsFull())
		{
			std::cout << " Is Full \n";
			extend();
		}
		data[mSize] = arg;
		mSize++;
	}
	void pop_back()
	{
		if (IsEmpty())
		{
			std::cout << "is empty \n";
			return;
		}
		mSize--;
	}
	void pop(int idx)
	{
		if (IsEmpty())
			return;
		for (int i = idx + 1; i < mSize; i++)
		{
			data[i - 1] = std::move(data[i]);
		}
		mSize--;
	}
	void push(int idx,const T& arg)
	{
		if (IsFull())
		{
			extend();
		}
		for (int i = mSize - 1; idx <= i; i--)
		{
			data[i + 1] = std::move(data[i]);
		}
		data[idx] = arg;
	}
	inline int size() { return mSize; }
private:
	T* data;
	int mSize = 0;
	int capacity = 2;

};


int main()
{
	Vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);


	vec.pop(4);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ", ";
	}
	std::cout << "\n";

	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	
	vec.push(4, 5);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << ", ";
	}
	std::cout << "\n";
	
}