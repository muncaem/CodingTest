#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	int size = strings.size();
	
	for (int i = 0; i < size; i++)
	{
		char change = strings[i][n];
        string s_change = string(1, change);
		strings[i].replace(n, 1, "");
		strings[i].insert(0, s_change);
	}
	
	sort(strings.begin(), strings.end());
	
	for (int i = 0; i < size; i++)
	{
		char change = strings[i][0];
        string s_change = string(1, change);
		strings[i].replace(0, 1, "");
		strings[i].insert(n, s_change);
	}
	
    return strings;
}