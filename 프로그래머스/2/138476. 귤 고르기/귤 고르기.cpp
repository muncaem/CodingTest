#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int numb = tangerine.size();
    
    sort(tangerine.begin(), tangerine.end()); // 오름차순 정렬
    
    int max = tangerine[0];
    int count = 1;
    vector<int> numbValSort;
    
    for (int i = 1; i < numb; i++)
    {
        if (max == tangerine[i]) // 같은 숫자 경우
        {
            count++;
        }
        else // 더 큰 숫자 경우
        {
            numbValSort.push_back(count);
            max = tangerine[i];
            count = 1;
        }
    }
    numbValSort.push_back(count);
    
    sort(numbValSort.begin(), numbValSort.end(), greater<>()); // 내림차순 정렬
    
    int collect = 0;
    for (int i = 0; i < numbValSort.size(); i++)
    {
        collect += numbValSort[i];
        answer++;
        if (collect >= k)
        {
            break;
        }
    }
    
    return answer;
}