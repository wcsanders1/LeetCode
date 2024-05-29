// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
  int numSteps(string s)
  {
    int answer = 0;
    while (s.size() > 1)
    {
      answer++;
      if (s[s.size() - 1] == '0')
      {
        s = s.substr(0, s.size() - 1);
      }
      else
      {
        s[s.size() - 1] = '0';
        int i = s.size() - 2;
        while (i >= 0 && s[i] == '1')
        {
          s[i--] = '0';
        }

        if (i < 0)
        {
          s = '1' + s;
        }
        else
        {
          s[i] = '1';
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numSteps("1101");
  int result2 = solution.numSteps("10");
  int result3 = solution.numSteps("1");
}