// https://leetcode.com/problems/next-greater-element-ii/
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    unordered_map<int, vector<int>> indeces;

    for (int i = 0; i < nums.size(); i++)
    {
      int num = nums[i];
      if (indeces.find(num) == indeces.end())
      {
        indeces[num] = vector<int>();
      }

      indeces[num].push_back(i);
    }

    stack<int> leasts;
    vector<int> answer(nums.size(), INT32_MIN);

    for (int i = 0; i < nums.size() * 2; i++)
    {
      int num = nums[i % nums.size()];
      if (leasts.empty() || num < leasts.top())
      {
        leasts.push(num);
      }
      else
      {
        while (!leasts.empty() && num > leasts.top())
        {
          int currentLeast = leasts.top();
          leasts.pop();

          for (int index : indeces[currentLeast])
          {
            if (answer[index] == INT32_MIN && index < i)
            {
              answer[index] = num;
            }
          }
        }
        leasts.push(num);
      }
    }

    for (int i = 0; i < answer.size(); i++)
    {
      if (answer[i] == INT32_MIN)
      {
        answer[i] = -1;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  vector<int> result1 = solution.nextGreaterElements(*new vector<int>{1, 2, 1});
  vector<int> result2 = solution.nextGreaterElements(*new vector<int>{1, 2, 3, 4, 3});
  vector<int> result3 = solution.nextGreaterElements(*new vector<int>{5, 4, 3, 2, 6, 1});
  vector<int> result4 = solution.nextGreaterElements(*new vector<int>{100, 1, 11, 1, 120, 111, 123, 1, -1, -100});
  vector<int> result5 = solution.nextGreaterElements(*new vector<int>{3, 2, -3, -1, 1, -3, 1, -1});
}