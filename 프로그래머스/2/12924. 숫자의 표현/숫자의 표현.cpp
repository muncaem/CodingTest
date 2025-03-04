#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int startNum = 1;
    int sum;

    for (int startNumb = 1; startNumb <= n / 2; startNumb++)
    {
        int i = startNumb;
        sum = 0;
        do
        {
            sum += i;
            if (sum > n)
                break;
            i++;
        }
        while (sum < n);

        if (sum == n)
            answer++;
    }
    
    return answer + 1;
}