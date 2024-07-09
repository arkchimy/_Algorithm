#include <iostream>
#include <windows.h>
#include <thread>


using namespace std;

unsigned int Increase(volatile unsigned int& a)
{
	for (int i = 0; i < 100000; i++)
		a++;
	return a ;
}

int main()
{
	volatile UINT_PTR a =0 ;

	thread th1(Increase, std::ref(a));
	thread th2(Increase, std::ref(a));

	th1.join();
	th2.join();

	cout << a;
	// volatile이 멀쓰 환경에서 일관성을 보장한다는 말은 틀린말이란걸 증명함.

	return 0;
}