// https://leetcode.com/problems/naming-a-company/description/
// NOT MINE: https://leetcode.com/problems/naming-a-company/solutions/2141172/java-c-python-group-by-first-letter/?orderBy=most_votes
#include <vector>
#include <unordered_set>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  long long distinctNames(vector<string> &ideas)
  {
    unordered_map<char, unordered_set<string>> m;

    for (string &idea : ideas)
    {
      if (m.count(idea[0]) == 0)
      {
        m[idea[0]] = unordered_set<string>();
      }

      m[idea[0]].insert(idea.substr(1));
    }

    long long answer = 0;
    for (int i = 'a'; i <= 'z'; i++)
    {
      for (int j = i + 1; j <= 'z'; j++)
      {
        long long c1 = 0;
        long long c2 = 0;
        for (auto &s : m[i])
        {
          if (m[j].count(s) == 0)
          {
            c1++;
          }
        }

        for (auto &s : m[j])
        {
          if (m[i].count(s) == 0)
          {
            c2++;
          }
        }

        answer += c1 * c2;
      }
    }

    return answer * 2;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.distinctNames(*new vector<string>{"coffee", "donuts", "time", "toffee"});                 // 6
  auto result2 = solution.distinctNames(*new vector<string>{"lack", "back"});                                       // 0
  auto result3 = solution.distinctNames(*new vector<string>{"phhrrjjcm", "zjfkpps", "pm", "fnpduelfe", "mxtvjnq"}); // 18
}