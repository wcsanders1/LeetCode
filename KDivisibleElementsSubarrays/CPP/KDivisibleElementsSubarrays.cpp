// https://leetcode.com/problems/k-divisible-elements-subarrays/description/
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution
{
public:
  int countDistinct(vector<int> &nums, int k, int p)
  {
    set<string> subs;

    for (int i = 0; i < nums.size(); i++)
    {
      string s = "";
      int divs = 0;
      for (int j = i; j < nums.size(); j++)
      {
        divs += nums[j] % p == 0 ? 1 : 0;
        if (divs > k)
        {
          break;
        }

        s += nums[j];
        subs.insert(s);
      }
    }

    return subs.size();
  }
};

int main()
{
  Solution solution;

  int result1 = solution.countDistinct(*new vector<int>{2, 3, 3, 2, 2}, 2, 2);
  int result2 = solution.countDistinct(*new vector<int>{1, 2, 3, 4}, 4, 1);
}