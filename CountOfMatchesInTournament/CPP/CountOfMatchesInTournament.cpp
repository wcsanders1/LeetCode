// https://leetcode.com/problems/count-of-matches-in-tournament/?envType=daily-question&envId=2023-12-05
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  int numberOfMatches(int n)
  {
    int answer = 0;
    while (n > 1)
    {
      int t = 0;
      if (n % 2 == 1)
      {
        t = 1;
      }

      n /= 2;
      answer += n;
      n += t;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numberOfMatches(7);
  int result2 = solution.numberOfMatches(14);
  int result3 = solution.numberOfMatches(1);
}