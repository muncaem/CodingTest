#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a; // 사전 순인지 체크
}

string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();
    vector<string> sNumb; 
    
    for (int i = 0; i < size; i++)
    {
        sNumb.push_back(to_string(numbers[i]));
    }
    
    sort(sNumb.begin(), sNumb.end(), compare); // 사전 순 정렬
    
    for (int i = 0; i < size; i++)
    {
        answer += sNumb[i];
    }
    
    if (answer[0] == '0')
    {
        return "0";
    }
    
    return answer;
}