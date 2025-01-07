#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    for (int i = 1; i < land.size(); i++)
    {
        // //키는 land value 값, value는 열 위치 값(열 개수 4열 고정)
        // map<int, int, greater<int>> m
        //     = {
        //         {land[i - 1][0], 0},
        //         {land[i - 1][1], 1},
        //         {land[i - 1][2], 2},
        //         {land[i - 1][3], 3}
        //     };
        //
        // vector<pair<int, int>> v(m.begin(), m.end());

        for (int k = 0; k < 4; k++)
        {
            // //제일 큰 값을 가진 열이 진행 중인 행의 열 번호랑 같을 경우
            // if (k == v[0].second)
            // {
            //     land[i][k] += v[1].first;
            // }
            // else
            // {
            //     land[i][k] += v[0].first;
            // }
            
            int max = 0;
            //바로 위 행 중에서 제일 큰 값 찾기
            for (int x = 0; x < 4; x++)
            {
                if (k != x)
                    max = std::max(max, land[i - 1][x]);
            }
            land[i][k] += max;
        }
    }

    return *max_element(land.back().begin(), land.back().end());
}