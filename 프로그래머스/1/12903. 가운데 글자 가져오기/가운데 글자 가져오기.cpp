#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int size = s.size();
    answer = size % 2 == 1 ? string(1, s[size / 2]) 
        : string(1, s[size / 2 - 1]) + string(1, s[size / 2]);
    return answer;
}