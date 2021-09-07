#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> results;
    vector<string> first;
    for (int i = 0; i < s.length(); i++)
    {
      first.push_back(string(1, s[i]));
    }

    results.push_back(first);

    return results;
  }

private:
  vector<vector<string> *> *getPalindromes(vector<string> &partitions, string s, int vectorStart, int stringStart)
  {
    vector<vector<string> *> *results = new vector<vector<string> *>;
    if (stringStart >= s.length())
    {
      return results;
    }

    for (int i = vectorStart; i < partitions.size(); i++)
    {
      for (int len = 1; len < s.length() - stringStart; len++)
      {
        string attempt = partitions[i] + s.substr(stringStart, len);
        if (isPalindrome(attempt))
        {
          vector<string> *newPartition = new vector<string>;
          for (int k = 0; k < i; k++)
          {
            newPartition->push_back(partitions[k]);
          }

          newPartition->push_back(attempt);

          for (int k = stringStart + len; k < s.length(); k++)
          {
            newPartition->push_back(string(1, s[k]));
          }

          results->push_back(newPartition);

          vector<vector<string> *> *newResults = getPalindromes(*newPartition, s, i + 1, stringStart + len);

          results->insert(end(*results), begin(*newResults), end(*newResults));
        }
      }

      return results;
    }
  }

  bool isPalindrome(string s)
  {
    int start = 0;
    int end = s.length() - 1;

    while (start < end)
    {
      if (s[start++] != s[end--])
      {
        return false;
      }
    }

    return true;
  }
};