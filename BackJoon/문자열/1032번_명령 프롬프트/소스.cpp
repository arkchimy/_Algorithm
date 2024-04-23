#include <iostream>
#include <string>

using namespace std;


int main()
{
    int n;
    cin >> n;
    n--;
    cin.ignore();
    string str;
    getline(cin,str);
    while (n--)
    {
        string temp;
        getline(cin,temp);

        for (int i =0; i < str.size(); i++)
        {
            if (str[i] != temp[i])
                str[i] = '?';
        }
    }
    cout << str;
}