#include <vector>

using namespace std;

int Calculation(int big, int small)
{
    if (small == 0)
        return big;
    else
        return Calculation(small, big % small);
}

vector<int> solution(int n, int m) {
    //최대공약수
    int max = m > n ? Calculation(m, n) : Calculation(n, m);
    //최소공배수
    int min = (n * m) / max;
    
    return {max, min};
}

int main()
{
    solution(3, 12);
    return 0;
}