// https://leetcode.com/problems/number-of-good-pairs/?envType=daily-question&envId=2023-10-03
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int numIdenticalPairs(vector<int> &nums)
  {
    unordered_map<int, int> m;
    int answer = 0;
    for (int n : nums)
    {
      if (m.count(n) == 0)
      {
        m[n] = 0;
      }

      if (m[n] == 0)
      {
        m[n] = 1;
      }
      else if (m[n] == 1)
      {
        m[n] = 2;
        answer++;
      }
      else
      {
        answer += m[n]++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numIdenticalPairs(*new vector<int>{1, 2, 3, 1, 1, 3});
  int result2 = solution.numIdenticalPairs(*new vector<int>{1, 1, 1, 1});
  int result3 = solution.numIdenticalPairs(*new vector<int>{1, 2, 3});
}