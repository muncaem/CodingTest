#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> arr)
{
    int answer = 1;
    int min;
    int max;

    sort(arr.begin(), arr.end()); //정렬 안해도 되나?
    min = arr[0];
    max = arr[1];
    for (int i = 1; i < arr.size(); i++)
    {
        int calc = min * max;
        answer = calc;

        while (max % min != 0)
        {
            int last = max % min; //나머지

            if (last > min)
                max = last;
            else
            {
                max = min;
                min = last;
            }
        }

        answer /= min;
        max = answer;
        if (i + 1 < arr.size())
            min = arr[i + 1];
    }

    return answer;
}