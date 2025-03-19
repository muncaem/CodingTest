#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> fib = {0, 1, 2};

    for (int i = 3; i <= n; i++)
        fib.push_back((fib[i - 1] + fib[i - 2]) % 1234567);
    
    return fib[n] % 1234567;
}