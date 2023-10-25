//#pragma once
#ifndef MYPRINT_H // �ߺ���� ����
#define MYPRINT_H


template <typename T>
void Print(const T& data, const char* message)
{
	std::cout << message;

	typename T::const_iterator iter = data.begin(); // const_iterator�� typename�� �Բ� ���Ǿ��Ѵ�.
	//std::cout << (*iter)++;const_iterator�� ��Ҹ� �����Ҽ�����. 
	std::cout << "( ";
	for (; iter != data.end(); iter++) // �����̳��� ��� ��� ���
		std::cout << *iter << ",";
	std::cout << ") ";
}



#endif // !MYPRINT_H
