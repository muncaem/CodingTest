#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> map;
    
    for (int i = 0; i < tangerine.size(); i++)
        map[tangerine[i]]++;

    vector<int> value;
    for (auto& p : map)
        value.push_back(p.second);
    sort(value.rbegin(), value.rend());

    int total = 0;
    for (auto i : value)
    {
        total += i;
        answer++;
        if (total >= k) break;
    }
    
    return answer;
}