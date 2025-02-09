#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    int removeValue = 0;
    int count = 0;
    
    while (s != "1")
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                removeValue++;
        }
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        
        count++;

        if (s == "1")
        {
            answer.push_back(count);
            answer.push_back(removeValue);
            return answer;
        }
        
        int newS = s.size();
        s = "";
        while (newS)
        {
            s += newS % 2 == 0 ? "0" : "1";
            newS /= 2;
        }
        std::reverse(s.begin(), s.end());
    }
    
    return answer;
}