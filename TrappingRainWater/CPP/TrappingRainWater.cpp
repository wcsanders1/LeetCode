// https://leetcode.com/problems/trapping-rain-water/description/?envType=daily-question&envId=2024-04-12
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  int trap(vector<int> &height)
  {
    int n = height.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    int curLeft = height[0];
    for (int i = 1; i < n; i++)
    {
      left[i] = curLeft;
      curLeft = max(curLeft, height[i]);
    }

    int curRight = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
      right[i] = curRight;
      curRight = max(curRight, height[i]);
    }

    int answer = 0;
    for (int i = 1; i < n - 1; i++)
    {
      int diff = min(left[i], right[i]);
      answer += max(0, diff - height[i]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.trap(*new vector<int>{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}); // 6
  int result2 = solution.trap(*new vector<int>{4, 2, 0, 3, 2, 5});                   // 9
  int result3 = solution.trap(*new vector<int>{5, 4, 1, 2});                         // 1
  int result4 = solution.trap(*new vector<int>{5, 2, 1, 2, 1, 5});                   // 14
  int result5 = solution.trap(*new vector<int>{2, 8, 5, 5, 6, 1, 7, 4, 5});          // 12
}