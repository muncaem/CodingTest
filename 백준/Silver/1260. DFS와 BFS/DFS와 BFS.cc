#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;
vector<int> graph[MAX]; // 인접 리스트
bool visited[MAX];

void dfs(int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < graph[v].size(); i++) {
        int next = graph[v][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // 양방향 연결
    }

    // 정점 번호가 작은 것부터 방문하기 위해 정렬
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS
    fill(visited, visited + MAX, false);
    dfs(v);
    cout << "\n";

    // BFS
    fill(visited, visited + MAX, false);
    bfs(v);
    cout << "\n";

    return 0;
}
