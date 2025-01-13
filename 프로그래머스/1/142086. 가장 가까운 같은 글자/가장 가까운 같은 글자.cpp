#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<char, int>> save;
	
    for (int i = 0; i < s.size(); i++)
    {
        auto key = s[i];
        auto it = find_if
        (save.begin(), save.end(), [&key](const pair<char, int>& p)
        {
            return p.first == key;
        });
		
        if (it != save.end())
        {
            answer.push_back(it->second);
            it->second = 0;
        }
        else
        {
            answer.push_back(-1);
            save.push_back(make_pair(s[i], 0));
        }
		
        for (int k = 0; k < save.size(); k++)
        {
            save[k].second += 1;
        }
    }
	
    return answer;
}