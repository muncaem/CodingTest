#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T = 0; // 테스트 케이스 개수
    int N = 0; // 지원자 수
    pair<int, int> score[100000];
    vector<int> recruiter;

    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> score[j].first >> score[j].second;
        }

        sort(score, score + N);

        int recruit = 0;
        int max = score[0].second; // 서류 최고 등수 기준 | 현재 최고 면접 순위
        recruit++; // 서류 최고 등수 채용
        for (int j = 1; j < N; j++)
        {
            if (score[j].second <= max) // 다른 지원자의 면접 순위가 더 높을 경우 채용
            {
                recruit++;
                max = score[j].second;
            }
        }

        recruiter.push_back(recruit);
    }

    for (int i = 0; i < T; i++)
    {
        cout << recruiter[i] << endl;
    }
    
    return 0;
}