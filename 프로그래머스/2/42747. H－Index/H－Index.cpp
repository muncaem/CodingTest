#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    while(true)
    {
        int count = 0;
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] >= answer) //인용된 논문 횟수가 answer보다 큰지 체크
                count++;
        }
        if (count >= answer)
            answer++;
        else
            break;
    }
    return answer - 1;
}