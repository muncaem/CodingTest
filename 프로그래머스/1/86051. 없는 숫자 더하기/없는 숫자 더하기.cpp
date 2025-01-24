#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int curSum = 0;
    for (int i = 0; i < numbers.size(); i++)
        curSum += numbers[i];
    
    return 45 - curSum;
}