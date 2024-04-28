#include <iostream>
#include <string>

using namespace std;

pair<string, string> distributeMoney(string total, string N)
{
    // total을 N으로 나누기
    string distribute;
    int remainder = 0;
    for (char c : total)
    {
        int digit = c - '0';
        int current = digit + remainder * 10;
        distribute.push_back((current / (N[0] - '0')) + '0');
        remainder = current % (N[0] - '0');
    }

    // distribute의 정수 부분을 구하기 위해 첫 번째 0을 찾음
    size_t decimalPointPos = distribute.find('.');
    if (decimalPointPos != string::npos)
    {
        distribute = distribute.substr(0, decimalPointPos);
    }

    // 남는 돈 계산
    string remaining = to_string(remainder);

    return make_pair(distribute, remaining);
}

int main()
{
    string total = "123456789012345678901234567890";
    string N = "987654321098765432109876543210";

    pair<string, string> result = distributeMoney(total, N);

    cout << "한 생명체에게 줄 돈의 양: " << result.first << endl;
    cout << "남는 돈: " << result.second << endl;

    return 0;
}