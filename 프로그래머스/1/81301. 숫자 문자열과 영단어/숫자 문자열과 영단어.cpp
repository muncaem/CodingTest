#include <map>
#include <string>

using namespace std;

map<string, int> m;
void Mapping()
{
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
}

int solution(string s)
{
    Mapping();
    string answer = "";
    string combi = "";

    for (char c : s)
    {
        if (atoi(&c) != 0 || c == '0') // 문자열이 아니거나 || 숫자 0을 그대로 나타내는거면 => 숫자다.
        {
            answer += c;
        }
        else // 문자이면
        {
            combi += c;
            if (combi.size() >= 3)
            {
                auto it = m.find(combi);
                if (m.find(combi) != m.end())
                {
                    combi = "";
                    answer += to_string(it->second);
                }
            }
        }
    }
    
    return stoi(answer);
}