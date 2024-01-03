// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int numberOfBeams(vector<string> &bank)
  {
    int answer = 0;
    int prevNum = 0;

    for (string &s : bank)
    {
      int curNum = 0;
      for (char &c : s)
      {
        curNum = c == '0' ? curNum : curNum + 1;
      }

      if (curNum > 0)
      {
        answer += curNum * prevNum;
        prevNum = curNum;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numberOfBeams(*new vector<string>{"011001", "000000", "010100", "001000"});
  int result2 = solution.numberOfBeams(*new vector<string>{"000", "111", "000"});
}