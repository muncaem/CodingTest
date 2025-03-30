#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    int idx = 0;
    for (long long i = left; i <= right; i++)
    {
        int val = 0;
        int quotient = i / n;
        int remainder = i % n;

        if (quotient >= remainder)
            val = quotient + 1;
        else
            val = (quotient + 1) + (remainder - quotient);
        
        answer.push_back(val);
    }
    
    return answer;
}