// https://leetcode.com/problems/merge-strings-alternately/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution
{
public:
  string mergeAlternately(string word1, string word2)
  {
    int p1 = 0;
    int p2 = 0;

    string answer = "";
    while (p1 < word1.size() || p2 < word2.size())
    {
      if (p1 < word1.size())
      {
        answer += word1[p1++];
      }

      if (p2 < word2.size())
      {
        answer += word2[p2++];
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.mergeAlternately("abc", "pqr");
  string result2 = solution.mergeAlternately("ab", "pqrs");
  string result3 = solution.mergeAlternately("abcd", "pq");
}