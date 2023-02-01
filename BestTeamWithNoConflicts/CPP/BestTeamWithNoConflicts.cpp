// https://leetcode.com/problems/best-team-with-no-conflicts/
#include <vector>
#include <algorithm>

using namespace std;

struct Player
{
  int score;
  int age;
  int total;
  Player(int s, int a) : score{s}, age{a}, total{s} {}
  Player() {}
};

class Solution
{
public:
  int bestTeamScore(vector<int> &scores, vector<int> &ages)
  {
    vector<Player> players;
    for (int i = 0; i < scores.size(); i++)
    {
      players.push_back(Player{scores[i], ages[i]});
    }

    auto sortByAge = [](const Player &p1, const Player &p2)
    {
      if (p1.age == p2.age)
      {
        return p1.score <= p2.score;
      }
      return p1.age < p2.age;
    };

    sort(players.begin(), players.end(), sortByAge);

    int answer = 0;
    for (int i = 0; i < players.size(); i++)
    {
      int temp = players[i].score;
      for (int j = i - 1; j >= 0; j--)
      {
        if (players[j].score <= players[i].score || players[j].age == players[i].age)
        {
          temp = max(temp, players[j].total + players[i].score);
        }
      }
      players[i].total = temp;
      answer = max(answer, temp);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.bestTeamScore(*new vector<int>{1, 3, 5, 10, 15}, *new vector<int>{1, 2, 3, 4, 5});                                                                            // 34
  int result2 = solution.bestTeamScore(*new vector<int>{4, 5, 6, 5}, *new vector<int>{2, 1, 2, 1});                                                                                    // 16
  int result3 = solution.bestTeamScore(*new vector<int>{1, 2, 3, 5}, *new vector<int>{8, 9, 10, 1});                                                                                   // 6
  int result4 = solution.bestTeamScore(*new vector<int>{319776, 611683, 835240, 602298, 430007, 574, 142444, 858606, 734364, 896074}, *new vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}); // 5431066
  int result5 = solution.bestTeamScore(*new vector<int>{9, 2, 8, 8, 2}, *new vector<int>{4, 1, 3, 3, 5});                                                                              // 27
  int result6 = solution.bestTeamScore(*new vector<int>{1, 3, 7, 3, 2, 4, 10, 7, 5}, *new vector<int>{4, 5, 2, 1, 1, 2, 4, 1, 4});
}