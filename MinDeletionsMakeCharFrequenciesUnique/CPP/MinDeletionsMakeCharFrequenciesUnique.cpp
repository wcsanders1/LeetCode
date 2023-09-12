// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/?envType=daily-question&envId=2023-09-12
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minDeletions(string s)
  {
    unordered_map<char, int> m;
    for (auto &c : s)
    {
      if (m.count(c) == 0)
      {
        m[c] = 0;
      }
      m[c]++;
    }

    vector<int> frequencies;
    for (auto &[k, v] : m)
    {
      frequencies.push_back(v);
    }

    sort(frequencies.begin(), frequencies.end(), greater<int>());

    int answer = 0;
    for (int i = 1; i < frequencies.size(); i++)
    {
      if (frequencies[i - 1] == 0)
      {
        answer += frequencies[i];
        frequencies[i] = 0;
      }
      else if (frequencies[i] >= frequencies[i - 1])
      {
        int diff = (frequencies[i] - frequencies[i - 1]) + 1;
        answer += diff;
        frequencies[i] -= diff;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minDeletions("aab");       // 0
  int result2 = solution.minDeletions("aaabbbcc");  // 2
  int result3 = solution.minDeletions("ceabaacb");  // 2
  int result4 = solution.minDeletions("aaabbbccc"); // 3
  int result5 = solution.minDeletions("abc");       // 2
  int result6 = solution.minDeletions("a");         // 0
  int result7 = solution.minDeletions("bbcebab");   // 2
}