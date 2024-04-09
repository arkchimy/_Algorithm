#include<iostream>

using namespace std;

typedef unsigned long long ull;
ull A;
int B, C;

int Pow(ull a, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return Pow( (a * a) % C , n / 2) % C;
    else if (n % 2 == 1)
        return a * Pow((a * a) % C, (n - 1) / 2) % C;
}

// 

//
//
//��� �Լ��� Ǯ �� n ����ŭ �ݺ��� �Ѵ�.
//n ���� ���ڸ� = >
//
//if n == 0 return 1;
//
//10 ^ 4  => (10 * 10 , n / 2 )
//
//100 ^ 5 =>  100 * (100 * 100, (n - 1) / 2)


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   
    cin >> A >> B >> C;

    cout << Pow(A, B);
}