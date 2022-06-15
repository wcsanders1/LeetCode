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
    indeces[nums[0]] = vector<int>{0};

    for (int i = 1; i < nums.size(); i++)
    {
      int num = nums[i];
      if (indeces.find(num) == indeces.end())
      {
        indeces[num] = vector<int>();
      }

      indeces[num].push_back(i);
    }

    stack<int> leasts;
    leasts.push(nums[0]);
    vector<int> answer(nums.size(), -1);

    for (int i = 1; i < nums.size(); i++)
    {
      int num = nums[i];
      if (leasts.empty() || num < leasts.top())
      {
        leasts.push(num);
      }

      while (!leasts.empty() && num > leasts.top())
      {
        int currentLeast = leasts.top();
        leasts.pop();

        for (int index : indeces[currentLeast])
        {
          answer[index] = num;
        }
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
}