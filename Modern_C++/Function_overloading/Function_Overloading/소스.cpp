#include <iostream>




template <typename T, typename T2>
void Add(T&& a, T2&& b)
{
	std::cout << a + b << "\n";
}

void Add(int& a, int& b)
{
	std::cout << a + b << "L-value Called \n";
	
}

void Add(int&& a, int&& b)
{
	std::cout << a + b << "R-value Called \n";
}


int main()
{

	int a,b;

	std::cin >> a >> b;
	//Add<int,int>(std::move(a), std::move(b));

	//Add(a, b); //  int& 타입의 L-Value
	Add<int,int>(std::move(a), std::move(b)); // int 의 && R-Value
	//Add(std::move(a), std::move(b)); // int 의 && R-Value
}