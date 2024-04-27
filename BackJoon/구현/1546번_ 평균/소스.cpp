#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    int best = 0;
    for (int i =0; i < n; i++)
    {
        cin >> vec[i];
        best = max(best, vec[i]);
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += double(vec[i])/best * 100.f;
    }
    cout << sum / n;
}