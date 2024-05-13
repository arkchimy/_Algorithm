#include <iostream>
#include <string>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int num = 0;
    while (n--)
    {
        string instruct;
        int data;
        cin >> instruct;
        if (instruct.compare("all") == 0)
        {
            num = 0;
            for (int i = 0; i < 20; i++)
                num += (1 << i);
            continue;
        }
        if (instruct.compare("empty") == 0)
        {
            num = 0;
            continue;
        }
        cin >> data;
        data--;
        if (instruct.compare("add") == 0)
        {
            num |= 1 << data; 
            
        }
        else if (instruct.compare("remove") == 0)
        {
            num &= ~(1 << data);
        }
        else if (instruct.compare("check") == 0)
        {
            cout << ((num & (1 << data)) == 1 << data ? "1\n" : "0\n");
        }
        else if (instruct.compare("toggle") == 0)
        {
            num ^= (1 << data);
        }


    }
}