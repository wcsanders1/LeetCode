// https://leetcode.com/problems/uncrossed-lines/
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<vector<int>> lcs(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++)
    {
      for (int j = 1; j <= n2; j++)
      {
        if (nums1[i - 1] == nums2[j - 1])
        {
          lcs[i][j] = lcs[i - 1][j - 1] + 1;
        }
        else
        {
          lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
      }
    }

    return lcs[n1][n2];
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxUncrossedLines(*new vector<int>{1, 4, 2}, *new vector<int>{1, 2, 4});
  int result2 = solution.maxUncrossedLines(*new vector<int>{2, 5, 1, 2, 5}, *new vector<int>{10, 5, 2, 1, 5, 2});
  int result3 = solution.maxUncrossedLines(*new vector<int>{1, 3, 7, 1, 7, 5}, *new vector<int>{1, 9, 2, 5, 1});
}