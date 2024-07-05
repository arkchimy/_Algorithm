#include <stdio.h>
#include <string>

int main()
{
	char str[] = "ABC한글";
	
	wchar_t wstr[] = L"ABC한글";
	

	printf("%d\n", strlen(str)); // 문자열의 길이가 7로 나오므로, 한글과 영어를 섞어쓸경우.
	// 문자열 로직에서 문제가 발생할 수 있다.

	printf("%d\n", sizeof(wstr)); // 한글이든 영어이든 항상 2바이트  (간혹 4바이트도있다고함.)
	printf("%d\n", wcslen(wstr)); // 문자열의 길이는 5가 나옴.
}