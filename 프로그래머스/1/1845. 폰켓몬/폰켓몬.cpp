#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int canHave = nums.size() / 2;
    
    unordered_set<int> type;

    for (int i = 0; i < nums.size(); i++)
    {
        type.insert(nums[i]);
    }

    int typeSize = type.size();
    
    if (typeSize >= canHave)
    {
        return canHave;
    }
    else
    {
        return typeSize;
    }
}