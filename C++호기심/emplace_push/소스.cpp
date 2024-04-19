#include <iostream>
#include <vector>	

using namespace std;

#define ARRSIZE 10000
class A
{
public:
	A()
	{
		for (int i = 0; i < ARRSIZE; i++)
			num[i] = i;
		cout << "construct" << endl;
	}
	~A()
	{
		cout << "destroy " << endl;

	}
	A(const A& org)
	{
		for (int i = 0; i < ARRSIZE; i++)
			num[i] = org.num[i];
		cout << "copy construct" << '\n';
	}
	A(const A&& org)
	{
		for (int i = 0; i < ARRSIZE; i++)
			num[i] = org.num[i];
		cout << "move construct" << '\n';
	}
	int num[ARRSIZE];

};
int main()
{
	//A a;
	//vector<A> local_vec;
	//local_vec.reserve(3);


	//cout << "==========================" << endl;
	//local_vec.push_back(a);   // 복사생성자 1번호출

	//local_vec.emplace_back(a);// 
	//local_vec.emplace_back(); //  


	vector<A*> vec;
	A* temp = new A();
	
	vec.push_back(temp); // 2ms
	vec.emplace_back();  // 1ms


	vec.push_back(new A()); // 6ms
	vec.emplace_back(new A());// 5MS
	vec.emplace_back();  // 1ms


}