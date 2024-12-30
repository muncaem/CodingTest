#include <string>

using namespace std;

bool Skip(char c, string skip)
{
    for (int i = 0; i < skip.size(); i++)
        if (c == skip[i]) return true;
    return false;
}

string solution(string s, string skip, int index)
{
    string answer = "";

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        for (int k = 0; k < index;)
        {
            c += 1;

            if (c > 'z')
                c -= 26;
            
            if (Skip(c, skip) == false) //스킵 문자 아니면 다음거
                k++;
        }

        answer += string(1, c);
    }
    return answer;
}