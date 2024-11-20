#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    std::queue<int> q;
    int qSum = 0;
    int index = 0;
    int size = truck_weights.size();

    for (int i = 0; i < bridge_length; i++)
    {
        q.push(0);
    }

    while(!q.empty())
    {
        qSum-= q.front();
        q.pop();
        answer++;

        if (index < size)
        {
            if (qSum + truck_weights[index] <= weight)
            {
                qSum += truck_weights[index];
                q.push(truck_weights[index]);
                index++;
            }
            else
            {
                q.push(0);
            }
        }
    }
    
    return answer;
}