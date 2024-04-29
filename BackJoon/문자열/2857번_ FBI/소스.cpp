#include <iostream>
#include <string>

using namespace std;


int main()
{
    string str;
    int cnt = 0;
    for (int i = 1; i <= 5; i++)
    {
        cin >> str;

        if (str.find("FBI") != string::npos)
        {
            cout << i << "\n";
            cnt++;
        }
    }
    if (!cnt)
        cout << "HE GOT AWAY!";
}