#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#define _T(x) __T(x)

#ifdef _UNICODE
	#define __T(x) L##x 
#else
	#define __T(x) x
#endif // _UNICODE

int _tmain()
{
	TCHAR str[] = _T("12345");

	_tprintf(_T("%d\n"), sizeof(str));

}
