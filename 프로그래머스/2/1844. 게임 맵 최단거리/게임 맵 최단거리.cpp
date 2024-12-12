#include<iostream>
#include <queue>
#include<vector>
using namespace std;

bool visited[101][101];
int dist[101][101] = {0, };

int dir[4][2] = {
    {-1, 0}, /*상*/
    {1, 0}, /*하*/
    {0, 1}, /*우*/
    {0, -1}
}; /*좌*/

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    queue<pair<int, int>> que;
    int size_v = maps.size();
    int size_h = maps[0].size();

    que.push(make_pair(0, 0));
    visited[0][0] = true;
    dist[0][0] = 1;

    while (!que.empty())
    {
        auto current = que.front();

        int x = current.first;
        int y = current.second;

        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];

            if (newX < 0 || newY < 0 || newX >= size_v || newY >= size_h
                || visited[newX][newY] || maps[newX][newY] == 0)
                continue;

            que.push(make_pair(newX, newY));
            visited[newX][newY] = true;
            dist[newX][newY] = dist[x][y] + 1;
        }
    }

    if (dist[size_v - 1][size_h - 1] == 0)
        return -1;
    else
        return dist[size_v - 1][size_h - 1];
}