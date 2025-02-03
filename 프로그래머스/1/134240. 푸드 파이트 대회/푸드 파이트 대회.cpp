#include <stack>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    stack<int> st;

    for (int i = 1; i < food.size(); i++)
    {
        int x = food[i] / 2;
        if (x > 0)
        {
            for (int k = 0; k < x; k++)
            {
                answer += to_string(i);
                st.push(i);   
            }
        }
    }
    answer += "0";

    while (!st.empty())
    {
        answer += to_string(st.top());
        st.pop();
    }
    
    return answer;
}