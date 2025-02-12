#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    bool isSpace = true;
    
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
        if (isSpace)
        {
            isSpace = false;
            if (isdigit(s[i]))//숫자면
                continue;
            else
                s[i] = toupper(s[i]);           
        }
        if (s[i] == ' ')
            isSpace = true;
    }
    
    return s;
}