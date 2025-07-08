#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> homeVarFromGroup;

int DFS(int x, int y)
{
    if (x < 0 || y < 0 || x >= map.size() || y >= map.size() || visited[x][y] || map[x][y] == 0)
        return 0;

    visited[x][y] = true;
    int count = 1; // 현재 위치 집 1개

    count += DFS(x - 1, y); //상
    count += DFS(x + 1, y); //하
    count += DFS(x, y - 1); //좌
    count += DFS(x, y + 1); //우

    return count;
}

int main() {
    int n; // n: 총 단지 수
    cin >> n;

    map.resize(n, vector<int>(n)); // 벡터 초기화
    visited.resize(n, vector<bool>(n, false));

    // 그래프 입력
    for (int i = 0; i < n; i++) {
        string homeRow;
        cin >> homeRow;
        for (int j = 0; j < homeRow.size(); j++)
        {
            map[i][j] = homeRow[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                int houseCount = DFS(i, j);
                homeVarFromGroup.push_back(houseCount);
            }
        }
    }

    sort(homeVarFromGroup.begin(), homeVarFromGroup.end());
    
    cout << homeVarFromGroup.size() << endl;
    for (int i = 0; i < homeVarFromGroup.size(); i++)
    {
        cout << homeVarFromGroup[i] << endl;
    }
    
    return 0;
}
