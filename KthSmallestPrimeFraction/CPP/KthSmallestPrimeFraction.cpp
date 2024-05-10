// https://leetcode.com/problems/k-th-smallest-prime-fraction/description/?envType=daily-question&envId=2024-05-10
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
  {
    vector<vector<double>> fractions;
    for (int i = 1; i < arr.size(); i++)
    {
      for (int j = 0; j < i; j++)
      {
        fractions.push_back({(double)arr[j] / arr[i], (double)arr[j], (double)arr[i]});
      }
    }

    sort(fractions.begin(), fractions.end());
    return {(int)fractions[k - 1][1], (int)fractions[k - 1][2]};
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.kthSmallestPrimeFraction(*new vector<int>{1, 2, 3, 5}, 3);
  auto result2 = solution.kthSmallestPrimeFraction(*new vector<int>{1, 7}, 1);
}