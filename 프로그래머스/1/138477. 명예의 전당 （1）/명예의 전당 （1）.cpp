#include <set>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;

    multiset<int> board; //명예의 전당
    for (int i : score)
    {
        board.insert(i);

        if (board.size() >= k + 1)
        {
            board.erase(board.begin());
        }

        answer.push_back(*board.begin());
    }

    return answer;
}