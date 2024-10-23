// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/?envType=daily-question&envId=2024-10-21
// NOT MINE: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/solutions/855153/c-brute-force/?envType=daily-question&envId=2024-10-21
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int maxUniqueSplit(string s)
  {
    unordered_set<string> subs;
    return maxUniqueSplit(s, subs, 0);
  }

private:
  int maxUniqueSplit(string &s, unordered_set<string> &subs, int start)
  {
    if (start == s.size())
    {
      return 0;
    }

    int result = -1;
    for (int size = 1; start + size <= s.size(); size++)
    {
      auto it = subs.insert(s.substr(start, size));
      if (it.second)
      {
        int nextResult = maxUniqueSplit(s, subs, start + size);
        if (nextResult != -1)
        {
          result = max(result, 1 + nextResult);
        }
        subs.erase(it.first);
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxUniqueSplit("ababccc");         // 5
  int result2 = solution.maxUniqueSplit("aba");             // 2
  int result3 = solution.maxUniqueSplit("aa");              // 1
  int result4 = solution.maxUniqueSplit("wwwzfvedwfvhsww"); // 11
}