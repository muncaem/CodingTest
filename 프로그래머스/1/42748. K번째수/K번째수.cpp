#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++)
    {
        multiset<int> split;
        for (int x = commands[i][0] - 1; x < commands[i][1]; x++)
        {
            split.insert(array[x]);
        }

        for (int k = 0; k < commands[i][2] - 1; k++)
        {
            split.erase(split.begin());
        }

        answer.push_back(*split.begin());
    }
    
    return answer;
}