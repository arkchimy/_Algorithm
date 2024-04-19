#include <iostream>

using namespace std;

class Animal
{
public:
	 virtual void Cry() { cout << "Animal \n"; } // 가상테이블 -> Cry , Cat::Cry
};

class Cat :public Animal
{
public:
	virtual void Cry() { cout << "Cat \n"; }
};
// sizeof();

// 다형성 
int main()
{
	Cat cat;
	Animal ani = cat; // 업 캐스팅
	ani.Cry();

}