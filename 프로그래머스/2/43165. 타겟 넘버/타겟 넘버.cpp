#include <string>
#include <vector>

using namespace std;

int count = 0;
void dfs(int idx, int accumulated, vector<int> numbers, int target)
{
    if (idx == numbers.size()) // 끝까지 다 더했을 경우(재귀 종료 조건)
    {
        if (accumulated == target)
            count++;
        return;
    }
    
    dfs(idx + 1, accumulated + numbers[idx], numbers, target); // 더할 경우
    dfs(idx + 1, accumulated - numbers[idx], numbers, target); // 뺄 경우
}

int solution(vector<int> numbers, int target) {
    dfs(0, 0, numbers, target);
    
    return count;
}