// https://leetcode.com/problems/majority-element-ii/?envType=daily-question&envId=2023-10-05
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int a = -1;
    int b = -1;
    int a_count = 0;
    int b_count = 0;

    for (int n : nums)
    {
      if (n == a)
      {
        a_count++;
      }
      else if (n == b)
      {
        b_count++;
      }
      else if (a_count == 0)
      {
        a = n;
        a_count = 1;
      }
      else if (b_count == 0)
      {
        b = n;
        b_count = 1;
      }
      else
      {
        a_count--;
        b_count--;
      }
    }

    a_count = 0;
    b_count = 0;
    for (int n : nums)
    {
      if (n == a)
      {
        a_count++;
      }
      else if (n == b)
      {
        b_count++;
      }
    }

    vector<int> answer;
    int third = nums.size() / 3;
    if (a_count > third)
    {
      answer.push_back(a);
    }
    if (b_count > third)
    {
      answer.push_back(b);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.majorityElement(*new vector<int>{3, 2, 3});
  auto result2 = solution.majorityElement(*new vector<int>{1});
  auto result3 = solution.majorityElement(*new vector<int>{1, 2});
}