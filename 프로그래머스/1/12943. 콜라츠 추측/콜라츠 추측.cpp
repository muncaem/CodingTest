#include <vector>

using namespace std;

int solution(int num) {
    int cnt = 0;
    long l_num = num;

    if (num == 1)
        return 0;
    
    do
    {
        l_num % 2 == 0 ? l_num /= 2 : l_num = l_num * 3 + 1;

        cnt++;
    }
    while (cnt < 500 && l_num != 1);

    if (l_num == 1)
        return cnt;
    else
        return -1;
}