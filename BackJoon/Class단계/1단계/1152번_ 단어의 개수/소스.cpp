
#include <iostream>
#include <string>
using namespace std;

int main() {

    char one[1000001];
    int a = 1;

    cin.getline(one, 1000001);

    for (int i = 0; i < 1000000; i++)
    {
        if (one[i] == NULL) break;
        if (one[i] == ' ') a++;

        if (one[i] == ' ' && one[i + 1] == NULL) a--;
    }

    if (one[0] == ' ') a--;

    cout << a;
    cout << endl;

    return 0;
}

//#include <iostream>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string str;
//	int cnt = 0;
//
//	getline(cin, str);
//
//	if (str.empty())
//	{
//		cout << 0;
//		return 0;
//	}
//
//	if (str[0] != ' ')
//		cnt++;
//
//	for_each(str.begin(), str.end(), [&cnt](char ch)
//		{
//			if (ch == ' ')
//				cnt++;
//		}
//	);
//	
//	if (str[str.size() - 1] == ' ')
//		cnt--;
//	cout << cnt;
//}