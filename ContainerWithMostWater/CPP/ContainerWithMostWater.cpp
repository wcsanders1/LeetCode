// https://leetcode.com/problems/container-with-most-water/description/
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
  int maxArea(vector<int> &height)
  {
    int n = height.size();
    int start = 0;
    int end = n - 1;
    int most = 0;
    while (start < end)
    {
      int m = (end - start) * min(height[end], height[start]);
      most = max(most, m);
      if (height[end] < height[start])
      {
        end--;
      }
      else if (height[end] > height[start])
      {
        start++;
      }
      else
      {
        end--;
        start++;
      }
    }

    return most;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxArea(*new vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7});
  int result2 = solution.maxArea(*new vector<int>{1, 1});
}