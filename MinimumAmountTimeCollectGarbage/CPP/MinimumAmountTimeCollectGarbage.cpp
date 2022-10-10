// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TimeTracker
{
  int spentTime;
  int potentialTime;
};

class Solution
{
public:
  int garbageCollection(vector<string> &garbage, vector<int> &travel)
  {
    unordered_map<char, TimeTracker> timeMap;
    timeMap['M'] = TimeTracker();
    timeMap['P'] = TimeTracker();
    timeMap['G'] = TimeTracker();

    for (int i = 0; i < garbage.size(); i++)
    {
      if (i > 0)
      {
        for (auto &[k, v] : timeMap)
        {
          v.potentialTime += travel[i - 1];
        }
      }

      for (char g : garbage[i])
      {
        timeMap[g].spentTime += timeMap[g].potentialTime + 1;
        timeMap[g].potentialTime = 0;
      }
    }

    int answer = 0;
    for (auto const &[k, v] : timeMap)
    {
      answer += v.spentTime;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.garbageCollection(*new vector<string>{"G", "P", "GP", "GG"}, *new vector<int>{2, 4, 3});
  int result2 = solution.garbageCollection(*new vector<string>{"MMM", "PGM", "GP"}, *new vector<int>{3, 10});
}