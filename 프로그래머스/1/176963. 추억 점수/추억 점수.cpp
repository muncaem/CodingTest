#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> val;
    
    for (int i = 0; i < yearning.size(); i++)
        val[name[i]] = yearning[i];

    for (auto p : photo)
    {
        int tmp = 0;
        for (int i = 0; i < p.size(); i++)
        {
            auto it = val.find(p[i]);
            if (it != val.end())
            {
                tmp += it->second;
            }
        }
        answer.push_back(tmp);
    }
    
    return answer;
}