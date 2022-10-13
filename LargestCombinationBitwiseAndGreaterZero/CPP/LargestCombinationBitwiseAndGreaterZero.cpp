// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
#include <vector>

using namespace std;

class Solution
{
public:
  int largestCombination(vector<int> &candidates)
  {
    vector<int> counter = vector<int>(sizeof(int) * 8, 0);
    int answer = 0;
    for (int c : candidates)
    {
      int i = 0;
      while (c > 0)
      {
        counter[i] += c & 1;
        answer = max(answer, counter[i]);
        c >>= 1;
        i++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.largestCombination(*new vector<int>{16, 17, 71, 62, 12, 24, 14});
  int result2 = solution.largestCombination(*new vector<int>{8, 8});
  int result3 = solution.largestCombination(*new vector<int>{1});
}