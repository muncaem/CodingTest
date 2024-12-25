#include <iostream>
#include <stack>
using namespace std;

int solution(string bracket)
{
    int value = 0;
    pair<char, char> pair;
    stack<char> s;

    for (int i = 0; i < bracket.size(); i++)
    {
        pair = make_pair(bracket[i], bracket[i + 1]);
        if (pair.first == '(' && pair.second == ')')
        {
            //레이저임
            value += s.size();
            i += 1;
            continue;
        }

        if (bracket[i] == '(')
        {
            s.push(bracket[i]);
        }
        else
        {
            if (s.empty() == false)
            {
                char top = s.top();
                if (top == '(')
                {
                    s.pop();
                    value++;
                }
                
            }
        }
    }

    return value;
}

int main()
{
    string bracket;
    cin >> bracket;

    cout << solution(bracket);
}