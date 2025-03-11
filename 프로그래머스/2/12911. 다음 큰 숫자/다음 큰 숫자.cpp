#include <string>

using namespace std;

string ToBinary(int numb)
{
    string n = "";
    do
    {
        n = to_string(numb % 2) + n;
        numb /= 2;
    }
    while (numb > 0);

    return n;
}

int OneValCheck(string numb)
{
    int val = 0;
    for (int i = 0; i < numb.size(); i++)
    {
        if (numb[i] == '1')
            val++;
    }

    return val;
}

int solution(int n)
{
    int oneVal = 0;
    oneVal = OneValCheck(ToBinary(n));

    do
    {
        n++;
    }
    while (OneValCheck(ToBinary(n)) != oneVal);

    return n;
}