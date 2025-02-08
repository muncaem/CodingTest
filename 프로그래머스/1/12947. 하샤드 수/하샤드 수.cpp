#include <string>

using namespace std;

bool solution(int x) {
    int k = 0;
    string tmp = to_string(x);
    for (int i = 0; i < tmp.size(); i++)
    {
        k += (int)tmp[i] - '0';
    }
    
    if (x % k == 0)
        return true;
    
    return false;
}