// https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/?envType=daily-question&envId=2026-08-20
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> resultArray(vector<int> &nums)
  {
    vector<int> arr1;
    vector<int> arr2;
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
      int num = nums[i];
      if (arr1[arr1.size() - 1] > arr2[arr2.size() - 1])
      {
        arr1.push_back(num);
      }
      else
      {
        arr2.push_back(num);
      }
    }

    arr1.insert(arr1.end(), arr2.begin(), arr2.end());

    return arr1;
  }
};