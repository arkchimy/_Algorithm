#include <iostream>
int Add(int a, int b)
{
	return a + b;
}

void Test(int a, int b)
{
	a += b;
}
#include <windows.h>
#include <thread>

int main()
{
	
	
	int num = 1;
	char ch = 1;

	int c = Add(1,2);
	unsigned long long a = 2147483647;
	long long b = 2147483647;

	unsigned long long* p1 = &a;
	long long* p2 = &b;


	std::thread th1(Test,a, b);

	th1.join();

	if (a == 2147483647)
	{
		std::cout << "a : " << a;
	}
	if (b == 2147483647)
	{
		std::cout << "b : " << b;
	}

	return 0;
}