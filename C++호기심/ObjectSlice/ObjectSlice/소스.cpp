#include <iostream>

using namespace std;

class Animal
{
public:
	 virtual void Cry() { cout << "Animal \n"; } // �������̺� -> Cry , Cat::Cry
};

class Cat :public Animal
{
public:
	virtual void Cry() { cout << "Cat \n"; }
};
// sizeof();

// ������ 
int main()
{
	Cat cat;
	Animal ani = cat; // �� ĳ����
	ani.Cry();

}