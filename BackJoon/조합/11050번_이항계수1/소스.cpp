#include <iostream>


using namespace std;


int Permutation(int n,int cnt)
{
    if (cnt == 0)
        return 1;
    if (n <= 1)
        return 1;
    return n * Permutation(n - 1, --cnt);
}
int Factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * Factorial(n - 1);
}
int main()
{
    int n, k;
    cin >> n >> k;

    cout << Permutation(n, k) / Factorial(k);
}