// https://leetcode.com/problems/transformed-array/description/?envType=daily-question&envId=2026-02-05
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> constructTransformedArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> answer(n, 0);
    for (int i = 0; i < n; i++)
    {
      int absIndex = nums[i] + i;
      if (absIndex < 0)
      {
        int index = abs(absIndex) > n ? n - (abs(absIndex) % n) : n - abs(absIndex);
        answer[i] = nums[index == n ? 0 : index];
      }
      else if (absIndex >= n)
      {
        int index = absIndex % n;
        answer[i] = nums[index];
      }
      else
      {
        answer[i] = nums[absIndex];
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto resutl1 = solution.constructTransformedArray(*new vector<int>{3, -2, 1, 1});
  auto resutl2 = solution.constructTransformedArray(*new vector<int>{-1, 4, -1});
  auto resutl3 = solution.constructTransformedArray(*new vector<int>{-10, -1});
  auto resutl4 = solution.constructTransformedArray(*new vector<int>{-10, -10, -4});
}