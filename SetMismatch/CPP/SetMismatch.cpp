// https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> findErrorNums(vector<int> &nums)
  {
    int prev = 0;
    vector<int> answer(2, 0);
    unordered_map<int, int> m;
    for (int n : nums)
    {
      m[n]++;
    }

    for (int i = 1; i <= nums.size(); i++)
    {
      if (m[i] == 2)
      {
        answer[0] = i;
      }

      if (m[i] == 0)
      {
        answer[1] = i;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findErrorNums(*new vector<int>{1, 2, 2, 4});
  auto result2 = solution.findErrorNums(*new vector<int>{1, 1});
  auto result3 = solution.findErrorNums(*new vector<int>{2, 2});
  auto result4 = solution.findErrorNums(*new vector<int>{3, 2, 3, 4, 6, 5}); // 3, 1
}