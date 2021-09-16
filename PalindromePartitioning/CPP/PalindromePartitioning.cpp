#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> results;
    if (s.empty())
    {
      return results;
    }

    vector<string> path;
    dfs(0, s, path, results);

    return results;
  }

private:
  void dfs(int index, string &s, vector<string> &path, vector<vector<string>> &results)
  {
    if (index == s.size())
    {
      results.push_back(path);
      return;
    }

    for (int i = index; i < s.size(); i++)
    {
      if (isPalindrome(s, index, i))
      {
        path.push_back(s.substr(index, i - index + 1));
        dfs(i + 1, s, path, results);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(const string &s, int start, int end)
  {
    while (start <= end)
    {
      if (s[start++] != s[end--])
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution solution;

  vector<vector<string>> results1 = solution.partition("aab");
}