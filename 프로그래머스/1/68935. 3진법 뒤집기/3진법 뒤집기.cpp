#include <cmath>
#include <string>

using namespace std;

int solution(int n)
{
    int answer = 0;
    string toThree = "";

    do
    {
        toThree += to_string(n % 3);
        n /= 3;
    }
    while (n / 3 > 0);
    if (n != 0)
        toThree += to_string(n);

    int cnt = 0;
    for (int i = toThree.size() - 1; i >= 0; i--)
        answer = answer + (toThree[cnt++] - '0') * pow(3, i);

    return answer;
}