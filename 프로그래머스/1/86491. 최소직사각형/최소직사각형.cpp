#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<pair<int, int>> p;

    for (auto i : sizes)
    {
        if (i[1] > i[0]) //세로가 가로보다 길면
        {
            p.push_back(make_pair(i[1], i[0]));
        }
        else
        {
            p.push_back(make_pair(i[0], i[1]));
        }
    }

    sort(p.begin(), p.end(), greater<>());

    int hMax = p[0].second;
    
    for (int i = 1; i < p.size(); i++)
    {
        if (hMax < p[i].second)
        {
            hMax = p[i].second;
        }
    }
    
    return p[0].first * hMax;
}