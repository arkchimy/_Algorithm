#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <inttypes.h>

//int ADD(int a, int b)
//{
//	return abs(b - a);
//}

UINT ADD32(UINT a, UINT b)
{
	UINT sum = a + b;
	return sum;
}

UINT_PTR ADD(UINT_PTR a, UINT_PTR b)
{
	UINT_PTR sum = a + b;
	return sum;
}
int _tmain()
{
	HANDLE hfile = CreateFile(_T("test.txt"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, NULL);
	if (hfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(_T("file not found %d"), GetLastError());
		return 0;
	}
	TCHAR str[] = _T("ABC한글 입니다.");
	_tprintf(_T("result : %zu") , ADD(UINT_MAX, 1));
	_tprintf(_T("\n result : %zu"), ADD32(UINT_MAX, 1));
 	//_tprintf(_T("Error Number : %d") ,GetLastError());
	
}