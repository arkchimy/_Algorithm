#include <stdio.h>
#include <string>

int main()
{
	char str[] = "ABC�ѱ�";
	
	wchar_t wstr[] = L"ABC�ѱ�";
	

	printf("%d\n", strlen(str)); // ���ڿ��� ���̰� 7�� �����Ƿ�, �ѱ۰� ��� ������.
	// ���ڿ� �������� ������ �߻��� �� �ִ�.

	printf("%d\n", sizeof(wstr)); // �ѱ��̵� �����̵� �׻� 2����Ʈ  (��Ȥ 4����Ʈ���ִٰ���.)
	printf("%d\n", wcslen(wstr)); // ���ڿ��� ���̴� 5�� ����.
}