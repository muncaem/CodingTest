#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k; //종류 갯수, 원하는 합
    // cin >> n >> k;
    scanf("%d %d", &n, &k);
    
    vector<int> type(n, 0); //동전 종류
    for (int i = 0; i < n; i++)
    {
        int coin;
        cin >> coin;
        
        type[i] = coin;
    }

    int needCoins = 0; //답

    for (int i = type.size() - 1; i >= 0; i--)
    {
        if (k <= 0) break;
        if (type[i] <= k)
        {
            while (k >= 0 && k >= type[i])
            {
                k -= type[i];
                needCoins++;
            }
        }
    }

    cout << needCoins;
    
    return 0;
}