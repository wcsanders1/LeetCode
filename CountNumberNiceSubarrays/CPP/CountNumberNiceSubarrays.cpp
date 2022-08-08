// https://leetcode.com/problems/count-number-of-nice-subarrays/
#include <vector>

using namespace std;

class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    vector<int> odds;
    for (int i = 0; i < nums.size(); i++)
    {
      if ((nums[i] % 2) != 0)
      {
        odds.push_back(i);
      }
    }

    if (odds.size() < k)
    {
      return 0;
    }

    int first = 0;
    int last = k - 1;
    int answer = 0;

    while (last < odds.size())
    {
      int before = first == 0 ? odds[first] : (odds[first] - odds[first - 1]) - 1;
      int after = last == odds.size() - 1 ? (nums.size() - odds[last]) - 1 : (odds[last + 1] - odds[last] - 1);

      if (before == 0 && after == 0)
      {
        answer++;
      }
      else if (before == 0)
      {
        answer += after + 1;
      }
      else if (after == 0)
      {
        answer += before + 1;
      }
      else
      {
        answer += (before + 1) * (after + 1);
      }

      first++;
      last++;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numberOfSubarrays(*new vector<int>{1, 1, 2, 1, 1}, 3);
  int result2 = solution.numberOfSubarrays(*new vector<int>{2, 4, 6}, 1);
  int result3 = solution.numberOfSubarrays(*new vector<int>{2, 2, 2, 1, 2, 2, 1, 2, 2, 2}, 2);
}