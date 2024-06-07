// https://leetcode.com/problems/hand-of-straights/description/?envType=daily-question&envId=2024-06-06
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool isNStraightHand(vector<int> &hand, int groupSize)
  {
    int n = hand.size();
    if (n % groupSize != 0)
    {
      return false;
    }

    int groupNum = n / groupSize;
    unordered_map<int, int> f;
    for (int n : hand)
    {
      if (++f[n] > groupNum)
      {
        return false;
      }
    }

    vector<int> nums;
    for (auto &[n, _] : f)
    {
      nums.push_back(n);
    }

    sort(nums.begin(), nums.end());
    while (groupNum-- > 0)
    {
      int start = 0;
      while (f[nums[start]] == 0 && start < nums.size())
      {
        start++;
      }

      for (int i = 0; i < groupSize; i++)
      {
        if (f[nums[start] + i] == 0)
        {
          return false;
        }
        f[nums[start] + i]--;
      }
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isNStraightHand(*new vector<int>{1, 2, 3, 6, 2, 3, 4, 7, 8}, 3);
  bool result2 = solution.isNStraightHand(*new vector<int>{1, 2, 3, 4, 5}, 4);
  bool result3 = solution.isNStraightHand(*new vector<int>{8, 10, 12}, 3);
}