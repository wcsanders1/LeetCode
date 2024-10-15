// https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  long long minimumSteps(string s)
  {
    long long answer = 0;
    int ones = 0;
    for (char &c : s)
    {
      if (c == '1')
      {
        ones++;
      }
      if (c == '0')
      {
        answer += ones;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.minimumSteps("101");
  long long result2 = solution.minimumSteps("100");
  long long result3 = solution.minimumSteps("0111");
}