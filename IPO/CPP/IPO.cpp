// https://leetcode.com/problems/ipo/
#include <vector>
#include <queue>

using namespace std;

struct Project
{
  int capital;
  int profit;

  Project(int c, int p)
  {
    capital = c;
    profit = p;
  }
};

class MaxProfit
{
public:
  bool operator()(Project p1, Project p2)
  {
    if (p1.profit == p2.profit)
    {
      return p1.capital > p2.capital;
    }

    return p1.profit < p2.profit;
  }
};

class MinCapital
{
public:
  bool operator()(Project p1, Project p2)
  {
    if (p1.capital == p2.capital)
    {
      return p1.profit < p2.profit;
    }

    return p1.capital > p2.capital;
  }
};

class Solution
{
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
  {
    priority_queue<Project, vector<Project>, MaxProfit> max_profit_queue;
    priority_queue<Project, vector<Project>, MinCapital> min_capital_queue;

    for (int i = 0; i < profits.size(); i++)
    {
      Project p = Project(capital[i], profits[i]);
      max_profit_queue.push(p);
    }

    int answer = w;
    while (k-- > 0)
    {
      while (max_profit_queue.top().capital > answer)
      {
        min_capital_queue.push(max_profit_queue.top());
        max_profit_queue.pop();

        if (max_profit_queue.empty())
        {
          return answer;
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findMaximizedCapital(2, 0, *new vector<int>{1, 2, 3}, *new vector<int>{0, 1, 1});
}