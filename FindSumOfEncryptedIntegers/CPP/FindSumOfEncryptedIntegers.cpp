// https://leetcode.com/problems/find-the-sum-of-encrypted-integers/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int sumOfEncryptedInt(vector<int> &nums)
  {
    int answer = 0;
    for (int &n : nums)
    {
      string s = to_string(n);
      int m = 0;
      int count = 0;
      for (char &c : s)
      {
        count++;
        m = max(m, c - '0');
      }

      int r = 0;
      while (count-- > 0)
      {
        r *= 10;
        r += m;
      }

      answer += r;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.sumOfEncryptedInt(*new vector<int>{1, 2, 3});
  int result2 = solution.sumOfEncryptedInt(*new vector<int>{10, 21, 31});
  int result3 = solution.sumOfEncryptedInt(*new vector<int>{2});
}