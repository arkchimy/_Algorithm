#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <vector>

#define MAX 10000000

using namespace std;

typedef long long ll;

vector<ll> vec;
vector<ll> prime;

ll a = 0, b = 0;

void sieve()
{
    for (ll i = 2; i <= MAX; i++)
    {
        if (vec[i] == false)
            continue;
        prime.push_back(i);
        for (int j = i * 2; j <= MAX; j += i)
            vec[j] = false;
        vec[i] = false;
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;
    vec.resize(MAX + 1, 1);

    int cnt = 0;

    sieve();

    // 소수들을 제곱하라.
    // 

    for (ll & num : prime)
    {
        ll n = 2;

        ll val = pow(num, n);
        while (a <= val && val <= b)
        {
            if (vec[val] != 100)
            {
                vec[val] = 100;
                cnt++;
            }
            val = pow(num, ++n);
        }
    }
    cout << cnt;
    return 0;
}