#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> copy = arr;
    
    sort(copy.begin(), copy.end());
    int small = copy[0];

    arr.erase(remove(arr.begin(), arr.end(), small), arr.end());
    
    if (arr.size() == 0)
        arr.push_back(-1);
    
    return arr;
}