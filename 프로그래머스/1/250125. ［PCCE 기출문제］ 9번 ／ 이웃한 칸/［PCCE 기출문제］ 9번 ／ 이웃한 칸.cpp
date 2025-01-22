#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w)
{
    int answer = 0;
    string target = board[h][w];

    if (h - 1 >= 0 && board[h - 1][w] == target)
        answer++;
    if (h + 1 < board.size() && board[h + 1][w] == target)
        answer++;
    if (w - 1 >= 0 && board[h][w - 1] == target)
        answer++;
    if (w + 1 < board.size() && board[h][w + 1] == target)
        answer++;

    return answer;
}