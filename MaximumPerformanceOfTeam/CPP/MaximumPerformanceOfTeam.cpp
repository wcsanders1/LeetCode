// https://leetcode.com/problems/maximum-performance-of-a-team/
#include <vector>
#include <queue>

using namespace std;

struct TeamMember
{
public:
  int speed;
  int efficiency;
  int index;
  bool used;

  TeamMember(int s, int e, int i) : speed(s), efficiency(e), index(i), used(false) {}
  TeamMember();
};

class MinSpeed
{
public:
  bool operator()(TeamMember *t1, TeamMember *t2)
  {
    return t1->speed > t2->speed;
  }
};

class MinEfficiency
{
public:
  bool operator()(TeamMember *t1, TeamMember *t2)
  {
    return t1->efficiency > t2->efficiency;
  }
};

class Solution
{
public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
  {
    priority_queue<TeamMember *, vector<TeamMember *>, MinSpeed> q_speed;
    priority_queue<TeamMember *, vector<TeamMember *>, MinEfficiency> q_efficiency;

    long long total_speed = 0;

    for (int i = 0; i < n; i++)
    {
      int s = speed[i];
      int e = efficiency[i];
      total_speed += s;
      TeamMember *tm = new TeamMember(s, e, i);
      q_speed.push(tm);
      q_efficiency.push(tm);
    }

    TeamMember *min_efficiency = q_efficiency.top();
    q_efficiency.pop();

    int m = 1000000007;
    int answer = (total_speed * min_efficiency->efficiency) % m;
    while (n-- > 1)
    {
      while (!q_speed.empty() && q_speed.top()->used)
      {
        q_speed.pop();
      }

      while (!q_efficiency.empty() && q_efficiency.top()->used)
      {
        q_efficiency.pop();
      }

      auto next_s = q_speed.top();
      auto next_e = q_efficiency.top();

      if (next_s->index == min_efficiency->index)
      {
        total_speed -= min_efficiency->speed;
        min_efficiency->used = true;
        min_efficiency = next_e;
        q_efficiency.pop();
        int a = (total_speed * min_efficiency->efficiency) % m;
        answer = n < k ? max(answer, a) : a;
        continue;
      }

      int p1 = ((total_speed - next_s->speed) * min_efficiency->efficiency) % m;
      int p2 = ((total_speed - min_efficiency->speed) * next_e->efficiency) % m;

      if (p1 > p2)
      {
        answer = n < k ? max(answer, p1) : p1;
        next_s->used = true;
        total_speed -= next_s->speed;
      }
      else
      {
        answer = n < k ? max(answer, p2) : p2;
        total_speed -= min_efficiency->speed;
        min_efficiency->used = true;
        min_efficiency = next_e;
        q_efficiency.pop();
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxPerformance(6,
                                        *new vector<int>{2, 10, 3, 1, 5, 8},
                                        *new vector<int>{5, 4, 3, 9, 7, 2}, 2); // 60
  int result2 = solution.maxPerformance(6,
                                        *new vector<int>{2, 10, 3, 1, 5, 8},
                                        *new vector<int>{5, 4, 3, 9, 7, 2}, 3); // 68
  int result3 = solution.maxPerformance(6,
                                        *new vector<int>{2, 10, 3, 1, 5, 8},
                                        *new vector<int>{5, 4, 3, 9, 7, 2}, 4); // 72
  int result4 = solution.maxPerformance(3,
                                        *new vector<int>{2, 8, 2},
                                        *new vector<int>{2, 7, 1}, 2); // 56
  int result5 = solution.maxPerformance(5,
                                        *new vector<int>{10, 10, 7, 9, 8},
                                        *new vector<int>{9, 8, 3, 6, 9}, 1); // 90
  int result6 = solution.maxPerformance(8,
                                        *new vector<int>{9, 9, 4, 6, 9, 7, 9, 8},
                                        *new vector<int>{1, 9, 1, 9, 8, 1, 10, 1}, 4); // 264
}