#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);

    for (int i = numbers.size() - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[i] < numbers[j]) //뒤에거가 더 크면
            {
                answer[i] = numbers[j];
                break;
            }
            else if (numbers[i] >= numbers[j]) //앞에거가 더 크거나 같으면
            {
                if (answer[j] == -1) //뒤에거보다 큰 수 없는 경우 넘어가기
                    break;
                else if (numbers[i] < answer[j])
                {
                    answer[i] = answer[j];
                    break;
                }
            }
        }
    }

    return answer;
}