#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    
    for (int i = 0; i < prices.size(); i++) {
        // 주식이 하락장이면 스택에 있는 것들이랑 하락 주가랑 비교해서 처내기
    while (!s.empty() && prices[i] < prices[s.top()]) {
        int topIndex = s.top();
        s.pop();
        answer[topIndex] = i - topIndex;
    }
    // 아직 가격이 떨어지지 않은 시점이라면 스택에 보류
    s.push(i);
    }

    // 스택에 남아 있는 건 끝까지 가격이 떨어지지 않은 것들
    while (!s.empty()) {
        int topIndex = s.top();
        s.pop();
        answer[topIndex] = prices.size() - 1 - topIndex;
    }
    
    return answer;
}