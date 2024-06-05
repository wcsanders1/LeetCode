// https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05
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
  vector<string> commonChars(vector<string> &words)
  {
    unordered_map<char, int> m;
    for (char &c : words[0])
    {
      m[c]++;
    }

    int n = words.size();
    for (int i = 1; i < n; i++)
    {
      unordered_map<char, int> nm;
      for (char &c : words[i])
      {
        nm[c]++;
      }

      for (auto &[c, i] : m)
      {
        m[c] = min(i, nm[c]);
      }
    }

    vector<string> answer;
    for (auto &[c, i] : m)
    {
      while (i-- > 0)
      {
        answer.push_back(string(1, c));
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.commonChars(*new vector<string>{"bella", "label", "roller"});
  auto result2 = solution.commonChars(*new vector<string>{"cool", "lock", "cook"});
}