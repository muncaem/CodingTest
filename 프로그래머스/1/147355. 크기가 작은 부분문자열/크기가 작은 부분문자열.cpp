#include <iostream>	

#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int len = p.size();
    unsigned long long intP = std::stoull(p);
	
    for (int i = 0; i <= t.size() - len; i++)
    {
        unsigned long long cut = std::stoull(t.substr(i, len));
	
        if (cut <= intP) answer++;
    }
	
    return answer;
}