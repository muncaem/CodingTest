#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int length = s.length();
    char front;
    stack<char> st;

    for (int i = 0; i < length; i++)
    {
        front = s[0];
        
        for (int k = 0; k < length; k++)
        {
            if (k == 0 && st.empty())
            {
                st.push(s[k]);
            }
            else if (s[k] == '(' || s[k] == '[' || s[k] == '{')
            {
                st.push(s[k]);
            }
            else
            {
                char top = st.top();

                if (s[k] == ')' && top == '(')
                {
                    st.pop();
                }
                else if (s[k] == ']' && top == '[')
                {
                    st.pop();
                }
                else if (s[k] == '}' && top == '{')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[k]);
                }
            }
        }

        if (st.empty()) answer++;
        
        while (!st.empty())
        {
            st.pop();
        }
        ///  !!!! 스택을 제대로 안 비워서 헤맸음 !!!!  for문으로 지우지 말고 empty일 때까지 while문으로 해야 제대로 지워짐 ///
        // for (int t = 0; t < st.size(); t++)
        // {
        //     //cout << "stack " << st.top() <<endl;
        //     st.pop();
        // }

        s.erase(s.begin());
        s += front;
    }
    
    return answer;
}