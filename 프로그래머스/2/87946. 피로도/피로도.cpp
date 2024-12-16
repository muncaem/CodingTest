#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[8];
int depth = 0;

void Search(int tired, vector<vector<int>> dungeons, int curDepth)
{
	if (depth < curDepth) depth = curDepth;

	for (int i = 0; i < dungeons.size(); i++)
	{
		if (visited[i] || dungeons[i][0] > tired) continue;
		
		visited[i] = true;
		Search(tired - dungeons[i][1], dungeons, curDepth + 1);
		visited[i] = false;
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	Search(k, dungeons, depth);
    return depth;
}