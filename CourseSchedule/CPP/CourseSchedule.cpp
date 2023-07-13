// https://leetcode.com/problems/course-schedule/description/
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

enum class State
{
  Unvisited,
  Visiting,
  CanTake,
  CannotTake
};

class Solution
{
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<State> states(numCourses, State::Unvisited);
    unordered_map<int, vector<int>> graph;

    for (auto &p : prerequisites)
    {
      if (graph.count(p[0]) == 0)
      {
        graph[p[0]] = vector<int>();
      }

      graph[p[0]].push_back(p[1]);
    }

    for (auto &p : prerequisites)
    {
      if (states[p[0]] == State::Unvisited)
      {
        if (!canTake(states, graph, p[0]))
        {
          return false;
        }
      }
    }

    return true;
  }

private:
  bool canTake(vector<State> &states, unordered_map<int, vector<int>> &graph, int course)
  {
    if (states[course] == State::Visiting || states[course] == State::CannotTake)
    {
      states[course] = State::CannotTake;
      return false;
    }

    if (states[course] == State::CanTake)
    {
      return true;
    }

    states[course] = State::Visiting;

    for (int p : graph[course])
    {
      if (!canTake(states, graph, p))
      {
        states[course] = State::CannotTake;
        return false;
      }
    }

    states[course] = State::CanTake;
    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.canFinish(2, *new vector<vector<int>>{{1, 0}});
  bool result2 = solution.canFinish(2, *new vector<vector<int>>{{1, 0}, {0, 1}});
}