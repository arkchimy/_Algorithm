#include <iostream>
using namespace std;


int main()
{
    int result = 1000;

    int a, b, c, d;

    cin >> a >> b >> c >> d;
    result = min(result, min(a, min(b, min(c - a, d - b))));

    cout << result;
}