#include <string>

using namespace std;

string solution(string s) {
    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            x = 0;
            continue;
        }
        
        if (x == 0 || x % 2 == 0) // 첫 번째(0번) 또는 짝수일 경우
        {
            s[i] = toupper(s[i]);
            x++;
        }
        else // 홀수일 경우
        {
            s[i] = tolower(s[i]);
            x++;
        }
    }
    
    return s;
}