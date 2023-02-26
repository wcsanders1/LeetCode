// https://leetcode.com/problems/find-the-divisibility-array-of-a-string/
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
  vector<int> divisibilityArray(string word, int m)
  {
    vector<int> answer;
    long long mod = 0;
    for (char s : word)
    {
      int d = s - '0';
      if ((mod + d) < m)
      {
        mod = (mod + d) * 10;
        answer.push_back(mod == 0 ? 1 : 0);
        continue;
      }

      long long t = (mod + d) % m;
      answer.push_back(t == 0 ? 1 : 0);

      mod = t * 10;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.divisibilityArray("998244353", 3);
  auto result2 = solution.divisibilityArray("1010", 10);
  auto result3 = solution.divisibilityArray("12", 3);
  auto result4 = solution.divisibilityArray("529282143571", 4);
  auto result5 = solution.divisibilityArray("86217457695827338571", 8);
  auto result6 = solution.divisibilityArray("4065582576255570359135118255554163128235573295923545700491253287387", 5);
}