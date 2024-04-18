#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str,str2;
    cin >> str;
   

    int result[2] = {0,0};
    
    char ch = str[0];

    if (ch == '0')
        result[0]++;
    else
        result[1]++;
    for (int i =1; i <str.size(); i++)
    {
        if (str[i] != ch)
        {
            if (str[i] == '0')
                result[0]++;
            else
                result[1]++;
            ch = str[i];
        }
    }
    printf("%d", min(result[0], result[1]));

}