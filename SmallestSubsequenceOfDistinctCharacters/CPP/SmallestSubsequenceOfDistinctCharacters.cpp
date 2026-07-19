// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/?envType=daily-question&envId=2026-07-19
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
  string smallestSubsequence(string s)
  {
    unordered_map<char, int> counts;
    for (char &c : s)
    {
      counts[c]++;
    }

    stack<char> mono;
    unordered_set<char> has;
    for (char &c : s)
    {
      if (has.find(c) == has.end())
      {
        while (!mono.empty() && mono.top() > c && counts[mono.top()] > 0)
        {
          has.erase(mono.top());
          mono.pop();
        }

        mono.push(c);
        has.insert(c);
      }
      counts[c]--;
    }

    string answer = "";
    while (!mono.empty())
    {
      answer += mono.top();
      mono.pop();
    }

    reverse(answer.begin(), answer.end());

    return answer;
  }
};

int main()
{
  Solution soltuion;

  string result1 = soltuion.smallestSubsequence("bcabc");
  string result2 = soltuion.smallestSubsequence("cbacdcbc");
  string result3 = soltuion.smallestSubsequence("bcbcbcababa"); // bca
}