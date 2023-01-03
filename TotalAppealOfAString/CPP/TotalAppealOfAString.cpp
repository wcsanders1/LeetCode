// https://leetcode.com/problems/total-appeal-of-a-string/
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  long long appealSum(string s)
  {
    vector<unordered_set<char>> chars(s.size());
    long long answer = 0;
    for (int i = 0; i < s.size(); i++)
    {
      for (int j = 0; j + i < s.size(); j++)
      {
        chars[j].insert(s[j + i]);
        answer += chars[j].size();
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.appealSum("abbca");
  long long result2 = solution.appealSum("code");
}