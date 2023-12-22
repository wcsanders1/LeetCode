// https://leetcode.com/problems/maximum-score-after-splitting-a-string/?envType=daily-question&envId=2023-12-22
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int maxScore(string s)
  {
    int n = s.size();
    vector<int> zeros(n, 0);
    vector<int> ones(n, 0);

    zeros[0] = s[0] == '0' ? 1 : 0;
    ones[n - 1] = s[n - 1] == '1' ? 1 : 0;
    for (int z = 1, o = n - 2; z < n; z++, o--)
    {
      zeros[z] = zeros[z - 1] + (s[z] == '0' ? 1 : 0);
      ones[o] = ones[o + 1] + (s[o] == '1' ? 1 : 0);
    }

    int answer = zeros[0];
    for (int i = 1; i < n; i++)
    {
      answer = max(answer, zeros[i - 1] + ones[i]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxScore("011101");
  int result2 = solution.maxScore("00111");
  int result3 = solution.maxScore("1111");
  int result4 = solution.maxScore("00");
  int result5 = solution.maxScore("01001");
}