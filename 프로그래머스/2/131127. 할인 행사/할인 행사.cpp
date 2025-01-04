#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    unordered_map<string, int> shoppingList;

    for (int i = 0; i < number.size(); i++)
    {
        shoppingList.insert(make_pair(want[i], number[i]));
    }

    for (int i = 0; i + 9 < discount.size(); i++)
    {
        bool canEnter = true;
        unordered_map<string, int> tmp(shoppingList);
        for (int j = i; j < i + 10; j++)
        {
            tmp[discount[j]]--;
        }
        for (auto list : tmp)
        {
            if (list.second > 0)
            {
                canEnter = false;
                break;
            }
        }
        if(canEnter) answer++;
    }

    return answer;
}