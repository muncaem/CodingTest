#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int DFS(int xIdx, int yIdx, const vector<string>& maps, vector<vector<bool>>& visited)
{    
    if (xIdx < 0 || yIdx < 0 || xIdx >= maps.size() || yIdx >= maps[0].size() || visited[xIdx][yIdx] || maps[xIdx][yIdx] == 'X') return 0;
    else
    {
        visited[xIdx][yIdx] = true; //방문처리
        int val = maps[xIdx][yIdx] - '0'; //식량 계산
        
        val += DFS(xIdx - 1, yIdx, maps, visited);//상
        val += DFS(xIdx + 1, yIdx, maps, visited); //하
        val += DFS(xIdx, yIdx - 1, maps, visited); //좌
        val += DFS(xIdx, yIdx + 1, maps, visited); //우
        
        return val;
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++)
        {
            if (maps[i][j] != 'X' && !visited[i][j]) //무인도가 아니고 방문하지 않았을 경우
            {
                int total = DFS(i, j, maps, visited);
                if (total > 0) answer.push_back(total);
            }
        }
    }
    
    if (answer.empty()) return {-1}; // 갈 수 없을 경우 -1 리턴
    sort(answer.begin(), answer.end());
    
    return answer;
}