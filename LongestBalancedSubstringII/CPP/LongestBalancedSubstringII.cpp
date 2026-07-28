// https://leetcode.com/problems/longest-balanced-substring-ii/description/?envType=daily-question&envId=2026-02-13
// NOT MINE: https://leetcode.com/problems/longest-balanced-substring-ii/solutions/7575065/step-by-step-by-balepavleski-nrkd/?envType=daily-question&envId=2026-02-13
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int longestBalanced(string s)
  {
    return max({mono(s), duo(s, 'a', 'b'), duo(s, 'a', 'c'), duo(s, 'b', 'c'), trio(s)});
  }

private:
  int mono(string &s)
  {
    int n = s.size();
    if (n < 2)
    {
      return n;
    }

    int count = 1;
    int mx = 0;
    for (int i = 1; i < n; i++)
    {
      if (s[i] == s[i - 1])
      {
        count++;
      }
      else
      {
        count = 1;
      }
      mx = max(mx, count);
    }

    return mx;
  }

  int duo(string &s, char c1, char c2)
  {
    int n = s.size();
    int delta = 0;
    int count = 0;
    unordered_map<int, int> pos;
    pos[0] = -1;
    for (int i = 0; i < n; i++)
    {
      char &c = s[i];
      if (c == c1)
      {
        delta++;
      }
      else if (c == c2)
      {
        delta--;
      }
      else
      {
        pos.clear();
        pos[0] = i;
        delta = 0;
      }

      if (pos.find(delta) != pos.end())
      {
        count = max(count, i - pos[delta]);
      }
      else
      {
        pos[delta] = i;
      }
    }

    return count;
  }

  int trio(string &s)
  {
    unordered_map<string, int> pos;
    pos["0,0"] = -1;
    int count = 0;
    vector<int> counts(3, 0);
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
      counts[s[i] - 'a']++;
      string key = to_string(counts[1] - counts[0]) + "," + to_string(counts[2] - counts[0]);
      if (pos.find(key) != pos.end())
      {
        count = max(count, i - pos[key]);
      }
      else
      {
        pos[key] = i;
      }
    }

    return count;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestBalanced("abbac"); // 4
  int result2 = solution.longestBalanced("aabcc"); // 3
  int result3 = solution.longestBalanced("aba");   // 2
  int result4 = solution.longestBalanced("accc");  // 3
  int result5 = solution.longestBalanced("a");     // 1
}