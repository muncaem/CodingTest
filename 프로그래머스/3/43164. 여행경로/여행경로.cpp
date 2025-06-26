#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

bool DFS(string now, const vector<vector<string>>& t, vector<bool>& visited, vector<string>& path, int depth)
{
    path.push_back(now);
    
    if (depth == t.size()) // 모두 사용했을 경우
    {
        answer = path;
        return true;
    }
    
    for (int i = 0; i < t.size(); i++)
    {
        if (!visited[i] && t[i][0] == now) // 방문하지 않은 곳 중에 현재 방문할 곳 찾기
        {
            visited[i] = true; // 방문 체크
            if (DFS(t[i][1], t, visited, path, depth + 1))
                return true;
            visited[i] = false; // 경로 못 찾으면 방문 체크 해제
        }
    }
    
    path.pop_back(); // 경로 못 찾으면 path 백트래킹
    return false; // 경로 찾기 실패 돌아가기
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end()); // 알파벳 순으로 정렬
    
    vector<bool> visited(tickets.size(), false);
    vector<string> path;
    
    DFS("ICN", tickets, visited, path, 0);
    
    return answer;
}