// https://leetcode.com/problems/longest-increasing-subsequence/description/
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
  int lengthOfLIS(vector<int> &nums)
  {
    vector<int> arr;
    for (int num : nums)
    {
      if (arr.size() == 0 || arr[arr.size() - 1] < num)
      {
        arr.push_back(num);
      }
      else
      {
        insert(arr, num);
      }
    }

    return arr.size();
  }

private:
  void insert(vector<int> &arr, int num)
  {
    int start = 0;
    int end = arr.size() - 1;
    while (start < end)
    {
      int mid = (end + start) / 2;
      if (arr[mid] == num)
      {
        return;
      }

      if (arr[mid] > num)
      {
        if (mid == 0)
        {
          arr[mid] = num;
          return;
        }
        if (arr[mid - 1] == num)
        {
          return;
        }
        if (arr[mid - 1] < num)
        {
          arr[mid] = num;
          return;
        }
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }

    arr[start] = num;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.lengthOfLIS(*new vector<int>{10, 9, 2, 5, 3, 7, 101, 18});        // 4
  int result2 = solution.lengthOfLIS(*new vector<int>{0, 1, 0, 3, 2, 3});                  // 4
  int result3 = solution.lengthOfLIS(*new vector<int>{7, 7, 7, 7, 7, 7, 7});               // 1
  int result4 = solution.lengthOfLIS(*new vector<int>{3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12}); // 6
}