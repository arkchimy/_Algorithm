#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

void vulnerable_function(const char* input)
{
	char buffer[10];
	strcpy(buffer, input);  // input�� buffer�� ũ��(10����Ʈ)�� �ʰ��ϸ� ���� �����÷ο� �߻�
}

int main() 
{
	int a, b, c;
	a = 10;
	b = 10;
	c = 10101;

	char large_input[] = "123456789";
	vulnerable_function(large_input);
	std::cout << large_input;
	
	vulnerable_function(large_input);
	std::cout << large_input;

	vulnerable_function(large_input);
	std::cout << large_input;

	vulnerable_function(large_input);
	std::cout << large_input;
	return 0;
}