#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int idx = 0;
    
    while(idx < s.size())
    {
        int xVal = 0; // x가 나온 횟수
        int nVal = 0; // x가 아닌 횟수
        
        char x = s[idx]; 
        xVal++;
        idx++; // 전체 인덱스 중 몇 번째 포커스인지 카운트
        
        while (idx < s.size()) {
            if (s[idx] == x) xVal++;
            else nVal++;

            idx++;

            if (xVal == nVal) break; // 분해 조건
        }
        
        answer++;
    }
    
    return answer;
}