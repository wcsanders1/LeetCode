// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/?envType=daily-question&envId=2023-12-21
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int maxWidthOfVerticalArea(vector<vector<int>> &points)
  {
    vector<int> xs;
    for (auto &p : points)
    {
      xs.push_back(p[0]);
    }

    sort(xs.begin(), xs.end());

    int answer = 0;
    for (int i = 1; i < xs.size(); i++)
    {
      answer = max(answer, xs[i] - xs[i - 1]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxWidthOfVerticalArea(*new vector<vector<int>>{{8, 7}, {9, 9}, {7, 4}, {9, 7}});
  int result2 = solution.maxWidthOfVerticalArea(*new vector<vector<int>>{{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}});
}