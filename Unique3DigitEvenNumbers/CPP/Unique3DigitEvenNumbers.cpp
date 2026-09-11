// https://leetcode.com/problems/unique-3-digit-even-numbers/description/?envType=daily-question&envId=2026-09-11
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int totalNumbers(vector<int> &digits)
  {
    unordered_map<int, int> counts;
    for (int &n : digits)
    {
      counts[n]++;
    }

    int answer = 0;
    for (int n = 100; n < 999; n += 2)
    {
      unordered_map<int, int> c;
      int num = n;
      while (num > 0)
      {
        int d = num % 10;
        c[d]++;
        num /= 10;
      }

      bool good = true;
      for (auto &[d, a] : c)
      {
        if (counts[d] < a)
        {
          good = false;
        }
      }

      if (good)
      {
        answer++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.totalNumbers(*new vector<int>{1, 2, 3, 4});
  int result2 = solution.totalNumbers(*new vector<int>{0, 2, 2});
  int result3 = solution.totalNumbers(*new vector<int>{6, 6, 6});
  int result4 = solution.totalNumbers(*new vector<int>{1, 3, 5});
}