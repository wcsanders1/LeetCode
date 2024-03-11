// https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11
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
  string customSortString(string order, string s)
  {
    unordered_map<char, int> count;
    for (char &c : s)
    {
      count[c]++;
    }

    vector<char> newS;
    for (char &c : order)
    {
      while (count[c] > 0)
      {
        count[c]--;
        newS.push_back(c);
      }
    }

    for (auto &[ch, cnt] : count)
    {
      while (cnt-- > 0)
      {
        newS.push_back(ch);
      }
    }

    return string(newS.begin(), newS.end());
  }
};

int main()
{
  Solution solution;

  string result1 = solution.customSortString("cba", "abcd");
  string result2 = solution.customSortString("bcafg", "abcd");
}