// https://leetcode.com/problems/ugly-number/description/
// NOT MINE: https://leetcode.com/problems/ugly-number/solutions/69214/2-4-lines-every-language-by-stefanpochma-zk0d/
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
  bool isUgly(int n)
  {
    for (int i = 2; i < 6 && n; i++)
    {
      while (n % i == 0)
      {
        n /= i;
      }
    }

    return n == 1;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isUgly(6);
  bool result2 = solution.isUgly(35);
}