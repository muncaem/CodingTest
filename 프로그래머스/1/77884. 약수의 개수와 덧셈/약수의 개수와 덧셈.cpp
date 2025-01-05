#include <math.h>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++)
    {
        auto x = sqrt(i);
        //x랑 1 나머지 연산 결과가 0이면 제곱수이다.
        if (fmod(x, 1) == 0)
            answer -= i;
        else
            answer += i;
    }
    return answer;
}