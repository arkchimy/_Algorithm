//#pragma once
#ifndef MYPRINT_H // 중복헤더 방지
#define MYPRINT_H


template <typename T>
void Print(const T& data, const char* message)
{
	std::cout << message;

	typename T::const_iterator iter = data.begin(); // const_iterator는 typename과 함께 사용되야한다.
	//std::cout << (*iter)++;const_iterator는 요소를 변경할수없다. 
	std::cout << "( ";
	for (; iter != data.end(); iter++) // 컨테이너의 모든 요소 출력
		std::cout << *iter << ",";
	std::cout << ") ";
}



#endif // !MYPRINT_H
