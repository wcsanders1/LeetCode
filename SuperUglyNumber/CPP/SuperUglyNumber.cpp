#include <vector>

using namespace std;

class Solution
{
public:
  int nthSuperUglyNumber(int n, vector<int> &primes)
  {
    vector<int> dp(n, 0);
    vector<int> pointers(primes.size(), 0);

    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
      int lowest = primes[0] * dp[pointers[0]];

      for (int p = 0; p < primes.size(); p++)
      {
        int attempt = primes[p] * dp[pointers[p]];
        if (attempt < lowest)
        {
          lowest = attempt;
        }
      }

      dp[i] = lowest;

      for (int p = 0; p < primes.size(); p++)
      {
        if ((primes[p] * dp[pointers[p]]) <= dp[i])
        {
          pointers[p]++;
        }
      }
    }

    return dp[n - 1];
  }
};

int main()
{
  Solution solution;
  int result1 = solution.nthSuperUglyNumber(12, *new vector<int>{2, 7, 13, 19});
  int result2 = solution.nthSuperUglyNumber(1, *new vector<int>{2, 3, 5});
}