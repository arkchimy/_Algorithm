#include<iostream>
#include <vector>


using namespace std;
vector<int> vec;
int main()
{
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    vec.reserve(1001);
    vec.emplace_back(0);

    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i =1; i <= 1000;i++ )
    {
        for (int k = 0 ; k < i; k++)
        {
            
            if (vec.size() == 1001)
                break;
            if (n <= vec.size() && vec.size() <= m)
                sum += i;
            vec.emplace_back(i);
        }
        if (vec.size() == 1001)
            break;
    }
    cout << sum;
   
    
}