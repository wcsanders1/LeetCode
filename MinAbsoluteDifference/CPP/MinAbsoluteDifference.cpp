// https://leetcode.com/problems/minimum-absolute-difference/description/?envType=daily-question&envId=2026-01-26
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr)
  {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int diff = INT32_MAX;
    for (int i = 1; i < n; i++)
    {
      diff = min(diff, abs(arr[i - 1] - arr[i]));
    }

    vector<vector<int>> answer;
    for (int i = 1; i < n; i++)
    {
      if (abs(arr[i - 1] - arr[i]) == diff)
      {
        answer.push_back({arr[i - 1], arr[i]});
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.minimumAbsDifference(*new vector<int>{4, 2, 1, 3});
  auto result2 = solution.minimumAbsDifference(*new vector<int>{1, 3, 6, 10, 15});
  auto result3 = solution.minimumAbsDifference(*new vector<int>{3, 8, -10, 23, 19, -4, -14, 27});
}