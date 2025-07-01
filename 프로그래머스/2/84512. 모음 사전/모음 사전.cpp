#include <string>
#include <vector>

using namespace std;

int index = 0;
vector<string> letter = {"A", "E", "I", "O", "U"};
bool found = false;

void DFS(string curr, string target)
{
    if (found) return; // 찾았을 경우 진행 중인 재귀 모두 return

    if (curr == target) // 타겟이랑 같으면 현재 재귀 종료, found 플래그 활성화
    {
        found = true;
        return;
    }
    
    if (curr.size() >= 5) // 문자열 길이가 최대 5자리 넘어가면 return
        return;
    
    for (int i = 0; i < letter.size(); i++)
    {
        if (found) return; // 찾았을 경우 for문 재귀 return
        index++;
        DFS(curr + letter[i], target);
    }
}

int solution(string word) {
    DFS("", word); // 빈 문자열부터 시작해서 A부터 채움
    return index;
}