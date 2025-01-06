#include <vector>
using namespace std;

vector<bool> isPrimeNumb;

bool IsPrime(int i, int total)
{
    for (int k = 2; k < i; k++)
    {
        if (isPrimeNumb[k] == true) continue;
        if (i % k == 0) return false;
    }

    //소수일 경우.
    for (int x = 2; x * i <= total; x++)
    {
        isPrimeNumb[x * i] = false;
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    isPrimeNumb.assign(n + 1, true);

    for (int i = 2; i <= n; i++)
    {
        if (isPrimeNumb[i])
        {
            isPrimeNumb[i] = IsPrime(i, n);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        //isPrimeNumb false인 거 갯수 세기
        if (isPrimeNumb[i] == false)
            answer++;
    }
    
    return answer;
}