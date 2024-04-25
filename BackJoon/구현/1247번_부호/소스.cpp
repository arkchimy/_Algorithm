#include <iostream>
#include <algorithm> // std::sort
#include <cmath>     // std::pow
#include <vector>
using namespace std;

bool sol(int a, int b, int c)
{
    // �� ���� ���̸� ����
    vector<int> sides{a,b,c};
 
    sort(sides.begin(), sides.end());

    // �� ���� ������ ���
    int side1_sq = sides[0] * sides[0];
    int side2_sq = sides[1] * sides[1];
    int hypotenuse_sq = sides[2] * sides[2];

    // ��Ÿ����� ������ �̿��Ͽ� �����ﰢ������ �Ǻ�
    return (side1_sq + side2_sq == hypotenuse_sq);
}

int main()
{
    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // �Է°��� ��� 0�� ��� ����
        if (a == 0 && b == 0 && c == 0)
            break;

        // �����ﰢ������ �Ǻ�
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