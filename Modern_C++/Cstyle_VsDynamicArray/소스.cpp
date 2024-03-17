#include <iostream>
#include <vector>
#include <array>
#include <memory>


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
class Player
{
public:
	~Player() = default;
public:
	vector<Weapon> causer; //

	void TestFunction2()
	{
		for (int i = 0; i < 100; i++)
			causer.push_back(Weapon());
	}
};


int main()
{

	Player* p = new Player(); // 8¹ÙÀÌÆ®
	p->TestFunction2();

	delete p;
	
}