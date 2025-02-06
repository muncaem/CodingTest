#include <string>
#include <vector>

using namespace std;

bool AllZeroCheck(string s)
{
    for (char c : s)
        if (c != '0') return false;
    return true;
}

bool DFS(string binary)
{
    //하나일 경우
    if (binary.length() == 1 || AllZeroCheck(binary))
        return true;

    int middle = binary.length() / 2;
    string left = binary.substr(0, middle);
    string right = binary.substr(middle + 1);

    //가운데가 0일 때 좌 또는 우가 1인 경우 판별 => 포화 이진 트리 조건 성립 안됨.
    if (binary[middle] == '1' && DFS(left) && DFS(right)) return true;
    return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        /// 2진수 구하기
        string binary  = "";
        long long tmp = numbers[i];
        while (tmp)
        {
            binary = to_string(tmp % 2) + binary;
            tmp /= 2;
        }

        /// 포화 이진 트리 노드 갯수 조건 확인
        int size = binary.size();
        int x = 1;
        int addLen;
        while (true)
        {
            x *= 2;
            if (x - 1 >= size)
            {
                addLen = x - 1- size;
                break;
            }
        }

        /// 더미 노드 추가
        string tmpStr = "";
        for (int i = 0; i < addLen; i++)
            tmpStr += "0";
        binary = tmpStr + binary;
        
        /// 포화 이진 트리 조건 성립하는지 확인
        answer.push_back(DFS(binary));
    }
    
    return answer;
}