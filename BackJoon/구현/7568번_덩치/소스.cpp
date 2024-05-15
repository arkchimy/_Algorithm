#include <iostream>
#include <vector>


using namespace std;

class A
{
  public:
    A(int a,int b) : key(a), weight(b){};
  public:
    bool operator > (const A& other)
    {
        return  other.key > key && other.weight >  weight; 
    }

  public:
    int key;
    int weight;
};
int main()
{
    int n;
    cin >> n;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<A,int>> vec;
    vec.reserve(n);
    for (int i =0;  i < n ; i++)
    {
        int a, b;
        cin >> a >> b;
        A temp(a, b);
        vec.emplace_back(temp,1);
    }
    for (int i =0; i < n ; i++)
    {
        for (int k =0; k < n; k++)
        {
            if (vec[i].first > vec[k].first)
                vec[i].second++;
        }
        cout <<  vec[i].second << " ";
    }
    
}