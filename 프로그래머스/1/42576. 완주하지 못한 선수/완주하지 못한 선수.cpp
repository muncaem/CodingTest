#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void mapping(vector<int>& hash, vector<string>& participant, vector<string>& completion)
{
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    
    for (int i = 0; i < participant.size() && i < completion.size(); i++)
    {
        if (participant[i] == completion[i])
        {
            hash[i] = 1;
        }
    }
}

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    vector<int> hast_table(participant.size(), 0);

    mapping(hast_table, participant, completion);

    for (int i = 0; i < participant.size(); i++)
    {
        if (hast_table[i] == 1) continue;
        else
        {
            answer = participant[i];
            break;
        }
    }
    return answer;
}