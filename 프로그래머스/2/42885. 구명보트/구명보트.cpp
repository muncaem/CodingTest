#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
	
	int front =0;
	int back=people.size()-1;
	
	sort(people.begin(),people.end());
	
	while(back >= front)
	{
		if(limit - people[front] >= people[back])
		{
			front++;
			back--;
		}
		else
		{
			back--;
		}
		answer++;
	}
	
    return answer;
}