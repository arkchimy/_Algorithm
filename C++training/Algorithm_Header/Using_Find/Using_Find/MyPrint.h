#pragma once

#include <string>
template <typename T>
void Print(const T& data)
{
	typename T::const_iterator iter = data.begin();

	std::cout << "(";
	for (; iter != data.end(); iter++)
	{
		std::cout << *iter << ",";
	}
	std::cout << ")"<<std::endl;
	
}

