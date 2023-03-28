// https://leetcode.com/problems/k-items-with-the-maximum-sum/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution
{
public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
  {
    int answer = min(numOnes, k);
    k -= numOnes + numZeros;
    if (k > 0)
    {
      answer -= min(k, numNegOnes);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.kItemsWithMaximumSum(3, 2, 0, 2);
  int result2 = solution.kItemsWithMaximumSum(3, 2, 0, 4);
}