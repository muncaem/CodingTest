#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    
    if (sqrt(n) >= 0 && floor(sqrt(n)) == sqrt(n))
    {
        answer = (sqrt(n) + 1) * (sqrt(n) + 1);
    }
    else
        answer = -1;
    return answer;
}