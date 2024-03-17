#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public:
	Student(string& name, string& day, string& month, string& year)
		:name(move(name))
	{
		if (month.size() == 1)
			month = "0" + month;
		if (day.size() == 1)
			day = "0" + day;
		num = year + month + day;
	}
	string name;
	string num;
};

bool comp(const Student& s1, const Student& s2)
{
	return  s1.num < s2.num;
}
int main()
{
	int n;
	cin >> n;
	string name, day, month, year;

	vector<Student> vec;
	while (n--)
	{
		cin >> name >> day >> month >> year;
		vec.emplace_back(name, day, month, year);
	}
	sort(vec.begin(), vec.end(),comp);

	cout << vec[vec.size() - 1].name << "\n" << vec[0].name;
	
}