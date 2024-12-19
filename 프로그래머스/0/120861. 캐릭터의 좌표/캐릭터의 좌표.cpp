#include <string>
#include <vector>

using namespace std;

int maxX;
int maxY;
pair<int, int> curPos;

pair<int, int> Move(string key, pair<int, int> pos)
{
	if (key == "left")
	{
		if (pos.first <= -maxX)
			return pos;
		else 
			return make_pair(pos.first - 1, pos.second);
	}
	else if (key == "right")
	{
		if (pos.first >= maxX)
			return pos;
		else 
			return make_pair(pos.first + 1, pos.second);
	}
	else if (key == "down")
	{
		if (pos.second <= -maxY)
			return pos;
		else 
			return make_pair(pos.first, pos.second - 1);
	}
	else
	{
		if (pos.second >= maxY)
			return pos;
		else 
			return make_pair(pos.first, pos.second + 1);
	}
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
	
	maxX = board[0] / 2;
	maxY = board[1] / 2;

	curPos = make_pair(0, 0);
	
	for (int i = 0; i < keyinput.size(); i++)
	{
		curPos = Move(keyinput[i], curPos);
	}
	
	answer.push_back(curPos.first);
	answer.push_back(curPos.second);
	
    return answer;
}