#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
int result[8];

void DFS(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        result[cnt] = i;
        DFS(cnt + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    DFS(0);
    
    return 0;
}