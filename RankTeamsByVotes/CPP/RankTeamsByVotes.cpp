// https://leetcode.com/problems/rank-teams-by-votes/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Team
{
  char team;
  vector<int> ranks;
  Team()
  {
    team = '\0';
    ranks = vector<int>();
  }

  Team(char t, int size)
  {
    team = t;
    ranks = vector<int>(size, 0);
  }
};

struct TeamSorter
{
  inline bool operator()(const Team &team1, const Team &team2)
  {
    for (int i = 0; i < team1.ranks.size(); i++)
    {
      if (team1.ranks[i] > team2.ranks[i])
      {
        return true;
      }

      if (team1.ranks[i] < team2.ranks[i])
      {
        return false;
      }
    }

    return team1.team < team2.team;
  }
};

class Solution
{
public:
  string rankTeams(vector<string> &votes)
  {
    unordered_map<char, Team> teams;

    for (string vote : votes)
    {
      for (int i = 0; i < vote.size(); i++)
      {
        char team = vote[i];
        if (teams.count(team) == 0)
        {
          teams[team] = Team(team, vote.size());
        }

        teams[team].ranks[i]++;
      }
    }

    vector<Team> ranks = vector<Team>();
    for (auto kv : teams)
    {
      ranks.push_back(kv.second);
    }

    sort(ranks.begin(), ranks.end(), TeamSorter());

    string answer = "";
    for (Team rank : ranks)
    {
      answer += rank.team;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.rankTeams(*new vector<string>{"ABC", "ACB", "ABC", "ACB", "ACB"});
  string result2 = solution.rankTeams(*new vector<string>{"WXYZ", "XYZW"});
  string result3 = solution.rankTeams(*new vector<string>{"ZMNAGUEDSJYLBOPHRQICWFXTVK"});
  string result4 = solution.rankTeams(*new vector<string>{"ABC", "ACB", "ABC", "ACB"});
}