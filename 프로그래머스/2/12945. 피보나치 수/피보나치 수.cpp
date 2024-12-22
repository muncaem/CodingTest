using namespace std;

int solution(int n)
{
    int answer[100001] = {0, };
    answer[0] = 0;
    answer[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        answer[i] = (answer[i - 1] + answer[i - 2]) % 1234567;
    }
    return answer[n] % 1234567;
}