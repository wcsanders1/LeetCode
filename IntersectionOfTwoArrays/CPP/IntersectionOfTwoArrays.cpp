// https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    vector<bool> exists(1000, false);
    for (int &n : nums1)
    {
      exists[n] = true;
    }

    vector<int> answer;
    for (int &n : nums2)
    {
      if (exists[n])
      {
        answer.push_back(n);
        exists[n] = false;
      }
    }

    return answer;
  }
};