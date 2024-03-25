// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  vector<int> findDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> count(n + 1, 0);
    for (int &num : nums)
    {
      count[num]++;
    }

    vector<int> answer;
    for (int i = 1; i <= n; i++)
    {
      if (count[i] == 2)
      {
        answer.push_back(i);
      }
    }

    return answer;
  }
};