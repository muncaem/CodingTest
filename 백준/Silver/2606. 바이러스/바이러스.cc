#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 101; // 컴퓨터 수는 최대 100개
vector<int> graph[MAX];
bool visited[MAX];
int countVal = 0;

void DFS(int target)
{
    visited[target] = true;
    countVal++;
    
    for (int i = 0; i < graph[target].size(); i++)
    {
        if (!visited[graph[target][i]])
        {
            DFS(graph[target][i]);
        }
    }
}

int main() {
    int n, m; // n: 컴퓨터 수, m: 연결 수
    cin >> n >> m;

    // 그래프 입력
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // 양방향 연결
    }

    DFS(1);
    cout << countVal - 1; // 본인 제외 count
    
    return 0;
}