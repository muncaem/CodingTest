#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x;
    cin >> x;

    vector<int> list(x + 1, 0);
    list[1] = 0;
    list[2] = 1;
    list[3] = 1;

    for (int i = 4; i <= x; i++)
    {
        if (i % 6 == 0)
        {
            list[i] = min(min(list[i / 3], list[i / 2]), list[i - 1]) + 1;
        }
        else if (i % 3 == 0)
        {
            list[i] = min(list[i / 3], list[i - 1]) + 1;
        }
        else if (i % 2 == 0)
        {
            list[i] = min(list[i / 2], list[i - 1]) + 1;
        }
        else
        {
            list[i] = list[i - 1] + 1;
        }
    }

    cout << list[x];
    return 0;
}
