// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/?envType=daily-question&envId=2026-03-07
// NOT MINE: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/solutions/7631262/solution-by-la_castille-yiau/
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
  int minFlips(string s)
  {
    int n = s.size();

    vector<int> ops(2, 0);
    for (int i = 0; i < n; i++)
    {
      ops[(s[i] ^ i) & 1]++;
    }

    int answer = min(ops[0], ops[1]);

    for (int i = 0; i < n - 1; i++)
    {
      ops[(s[i] ^ i) & 1]--;
      ops[(s[i] ^ (i + n)) & 1]++;
      answer = min(answer, min(ops[0], ops[1]));
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minFlips("111000");      // 2
  int result2 = solution.minFlips("010");         // 0
  int result3 = solution.minFlips("1110");        // 1
  int result4 = solution.minFlips("110");         // 0
  int result5 = solution.minFlips("01001001101"); // 2
}