// https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/description/
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int maximumLength(vector<int> &nums)
  {
    unordered_map<long long, int> m;
    for (int &n : nums)
    {
      m[n]++;
    }

    int answer = 1;
    int ones = 0;
    for (int &n : nums)
    {
      if (n == 1)
      {
        ones++;
        continue;
      }

      long long needed = n;
      int temp = 0;
      while (m[needed] > 0)
      {
        if (m[needed] > 1 && m[needed * needed] > 0)
        {
          temp += 2;
          needed *= needed;
        }
        else
        {
          temp++;
          break;
        }
      }

      answer = max(temp, answer);
    }

    ones = ones % 2 == 0 ? ones - 1 : ones;
    return max(answer, ones);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maximumLength(*new vector<int>{5, 4, 1, 2, 2});
  int result2 = solution.maximumLength(*new vector<int>{1, 2, 3, 4});
  int result3 = solution.maximumLength(*new vector<int>{1, 1});
  int result4 = solution.maximumLength(*new vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024});
}