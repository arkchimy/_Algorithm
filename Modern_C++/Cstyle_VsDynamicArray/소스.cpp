#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <algorithm>


using namespace std;


class Weapon 
{
public:
	~Weapon()
	{
		cout << "Destructor Called \n";
	}
public:
	int mPower = 1.f; // 4Byte
};
//class Player
//{
//public:
//	~Player() = default;
//public:
//	vector<Weapon> causer; //
//
//	void TestFunction2()
//	{
//		for (int i = 0; i < 100; i++)
//			causer.push_back(Weapon());
//	}
//};


int main()
{

	Weapon sword; // 4¹ÙÀÌÆ®

	cout << sizeof(sword);

	vector<Weapon*> vec;
	for (int i = 0; i < 5; i++)
		vec.emplace_back(new Weapon());

	for_each(vec.begin(), vec.end(), [](Weapon* w) {cout << (long)w << "\n"; });
	
	
}