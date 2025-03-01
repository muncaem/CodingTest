#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int size = s.size();
    
    if (size != 4 && size != 6)
        return false;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]) != 0)
            continue;
        else answer = false;
    }
    
    return answer;
}