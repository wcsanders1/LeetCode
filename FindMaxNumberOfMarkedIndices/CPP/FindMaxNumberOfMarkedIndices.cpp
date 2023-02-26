// https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxNumOfMarkedIndices(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    vector<int> mult;
    for (int n : nums)
    {
      mult.push_back(n * 2);
    }

    vector<bool> marked(nums.size(), false);
    int start = nums.size() / 2;

    for (int i = 0; i < mult.size(); i++)
    {
      if (marked[i])
      {
        continue;
      }
      while (start < nums.size())
      {
        if (marked[start])
        {
          start++;
          continue;
        }
        if (nums[start] >= mult[i])
        {
          marked[i] = true;
          marked[start] = true;
          start++;
          break;
        }
        start++;
      }
    }

    int answer = 0;
    for (bool m : marked)
    {
      if (m)
      {
        answer++;
      }
    }
    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxNumOfMarkedIndices(*new vector<int>{3, 5, 2, 4});
  int result2 = solution.maxNumOfMarkedIndices(*new vector<int>{9, 2, 5, 4});
  int result3 = solution.maxNumOfMarkedIndices(*new vector<int>{7, 6, 8});
  int result4 = solution.maxNumOfMarkedIndices(*new vector<int>{1, 78, 27, 48, 14, 86, 79, 68, 77, 20, 57, 21, 18, 67, 5, 51, 70, 85, 47, 56, 22, 79, 41, 8, 39, 81, 59, 74, 14, 45, 49, 15, 10, 28, 16, 77, 22, 65, 8, 36, 79, 94, 44, 80, 72, 8, 96, 78, 39, 92, 69, 55, 9, 44, 26, 76, 40, 77, 16, 69, 40, 64, 12, 48, 66, 7, 59, 10}); // 64
}