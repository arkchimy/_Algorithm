#include <semaphore>
#include <iostream>
#include <thread>

using namespace std;

binary_semaphore sem(1);
int sum;

void FucA(int id)
{
	sem.acquire();// wait
	cout << "FuncA   " <<  sum++ <<  "\n";
	
	sem.release();

}
void FucB(int id)
{
	sem.acquire();// wait
	cout << "FuncB   " <<  sum++ << "\n";
	sem.release();
	
}

int main()
{
	jthread thA(FucA, 0);
	jthread	thB(FucB,1);

}

