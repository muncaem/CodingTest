#include <queue>
#include <string>
#include <set>

using namespace std;

string solution(string s)
{
    string answer = "";
    multiset<int> set;
    queue<char> q;

    for (int i = 0; i < s.size(); i++)
    {
        // 공백이 아니면
        if (isspace(s[i]) == 0)
        {
            q.push(s[i]);
        }
        else
        {
            string x = "";
            while(!q.empty())
            {
                x += q.front();
                q.pop();
            }
            set.insert(stoi(x));
        }
    }
    string x = "";
    while(!q.empty())
    {
        x += q.front();
        q.pop();
    }
    set.insert(stoi(x));
    answer += to_string(*set.begin()) + " " + to_string(*set.rbegin());
    return answer;
}