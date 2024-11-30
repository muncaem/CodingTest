#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    //크기가 n인 vector 0으로 초기화
    vector<bool> tree(n, false);

    //궁금한 위치의 인덱스
    tree[a] = true;
    tree[b] = true;

    //바로 붙어있는 경우
    for (int i = 0; i < n; i += 2)
    {
        if (tree[i] && tree[i + 1] == true)
        {
            return answer;
        }
    }

    vector<bool> r;

    while (true)
    {
        r.clear();
        answer++;

        for (int i = 0; i < n; i += 2)
        {
            r.push_back(tree[i] || tree[i + 1]);
        }

        for (int i = 0; i < r.size(); i += 2)
        {
            if (r[i] && r[i + 1] == true)
            {
                return answer;
            }
        }

        swap(tree, r);
        n /= 2;
    }
}