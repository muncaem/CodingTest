#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string s) {
    string answer = "";
    multiset<int, greater<>> m;
    
    for (int i = 0; i < s.size(); i++)
        m.insert(s[i]);
    
    for (auto iter = m.begin(); iter != m.end(); iter++)
        answer += *iter;
    
    return answer;
}