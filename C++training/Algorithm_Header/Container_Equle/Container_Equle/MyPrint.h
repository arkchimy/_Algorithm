#pragma once
#include <iomanip>
template <typename T>
void Print(const T& data, const char* message)
{
	std::cout <<std::fixed<<std::setprecision(10)<< message << " : ";
	std::cout << "(";
	typename T::const_iterator iter = data.begin();
	for (; iter != data.end(); iter++)
		std::cout << *iter << " ,";
	std::cout << ")" << std::endl;
}