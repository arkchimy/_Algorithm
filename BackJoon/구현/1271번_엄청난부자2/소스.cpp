#include <iostream>
#include <string>

using namespace std;

pair<string, string> distributeMoney(string total, string N)
{
    // total�� N���� ������
    string distribute;
    int remainder = 0;
    for (char c : total)
    {
        int digit = c - '0';
        int current = digit + remainder * 10;
        distribute.push_back((current / (N[0] - '0')) + '0');
        remainder = current % (N[0] - '0');
    }

    // distribute�� ���� �κ��� ���ϱ� ���� ù ��° 0�� ã��
    size_t decimalPointPos = distribute.find('.');
    if (decimalPointPos != string::npos)
    {
        distribute = distribute.substr(0, decimalPointPos);
    }

    // ���� �� ���
    string remaining = to_string(remainder);

    return make_pair(distribute, remaining);
}

int main()
{
    string total = "123456789012345678901234567890";
    string N = "987654321098765432109876543210";

    pair<string, string> result = distributeMoney(total, N);

    cout << "�� ����ü���� �� ���� ��: " << result.first << endl;
    cout << "���� ��: " << result.second << endl;

    return 0;
}