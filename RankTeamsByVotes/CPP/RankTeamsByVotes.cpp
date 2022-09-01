// https://leetcode.com/problems/rank-teams-by-votes/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  string rankTeams(vector<string> &votes)
  {
    vector<unordered_set<char>> positions = vector<unordered_set<char>>(votes.size(), unordered_set<char>());
    unordered_map<char, vector<int>> position_map = unordered_map<char, vector<int>>();
    unordered_map<char, bool> used = unordered_map<char, bool>();

    for (string vote : votes)
    {
      for (int i = 0; i < vote.size(); i++)
      {
        char team = vote[i];

        if (position_map.count(team) == 0)
        {
          position_map[team] = vector<int>(vote.size(), 0);
          used[team] = false;
        }

        position_map[team][i]++;
        positions[i].insert(team);
      }
    }

    string answer = "";

    for (int i = 0; i < positions.size(); i++)
    {
      unordered_map<char, int> score;
      for (char team : positions[i])
      {
        if (!used[team])
        {
          used[team] = true;
          score[team] = 0;
        }
      }
        }

    return answer;
  }
};