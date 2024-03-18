#include <iostream>
#include <vector>
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


int main()
{

	Weapon sword; // 4바이트

	cout << "Weapon의 크기 사이즈 : " << sizeof(sword) << "\n";

	vector<Weapon*> vec; 
	for (int i = 0; i < 5; i++)
		vec.emplace_back(new Weapon());


	cout << " Vec[i] 의 주소가 연속적 \n";
	for (int i = 0; i < vec.size(); i++)
		cout << &vec[i] << "\n";

}