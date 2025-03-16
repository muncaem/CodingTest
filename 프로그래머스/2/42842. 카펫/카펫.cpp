#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int row = brown / 2 - 1;
    int i = 1;
    
    while((row - 2) * i != yellow)
    {
        row--;
        i++;
    }
    
    return {row, i + 2};
}