#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++)
    {
        if (isspace(s[i]) != 0)
        {
            answer += " ";
            continue;
        }
        if (isupper(s[i]))
        {
            answer += s[i] + n > 'Z' ? s[i] + n - 90 + 64 : s[i] + n;
        }
        else
        {
            answer += s[i] + n > 'z' ? s[i] + n - 122 + 96 : s[i] + n;
        }
    }
    
    return answer;
}