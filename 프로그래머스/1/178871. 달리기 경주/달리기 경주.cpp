#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;
    map<string, int> playerKey;
    map<int, string> seqKey;

    int findIdx;
    string changePlayer;

    for (int i = 0; i < players.size(); i++)
    {
        playerKey[players[i]] = i;
        seqKey[i] = players[i];
    }

    for (int i = 0; i < callings.size(); i++)
    {
        findIdx = playerKey[callings[i]];
        changePlayer = seqKey[findIdx - 1];
        
        seqKey[findIdx] = changePlayer;
        seqKey[findIdx - 1] = callings[i];

        playerKey[callings[i]] = findIdx - 1;
        playerKey[changePlayer] = findIdx;
    }

    for (auto p : seqKey)
        answer.push_back(p.second);

    return answer;
}