#include <iostream>
#include <algorithm> // std::sort
#include <cmath>     // std::pow
#include <vector>
using namespace std;

bool sol(int a, int b, int c)
{
    // 세 변의 길이를 정렬
    vector<int> sides{a,b,c};
 
    sort(sides.begin(), sides.end());

    // 각 변의 제곱값 계산
    int side1_sq = sides[0] * sides[0];
    int side2_sq = sides[1] * sides[1];
    int hypotenuse_sq = sides[2] * sides[2];

    // 피타고라스의 정리를 이용하여 직각삼각형인지 판별
    return (side1_sq + side2_sq == hypotenuse_sq);
}

int main()
{
    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // 입력값이 모두 0인 경우 종료
        if (a == 0 && b == 0 && c == 0)
            break;

        // 직각삼각형인지 판별
        if (sol(a, b, c))
        {
            cout << "right" << "\n";
        }
        else
        {
            cout << "wrong" << "\n";
        }
    }

    return 0;
}