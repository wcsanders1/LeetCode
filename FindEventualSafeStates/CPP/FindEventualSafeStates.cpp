// https://leetcode.com/problems/find-eventual-safe-states/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

enum class State
{
  Unvisited,
  Current,
  Safe,
  Unsafe
};

class Solution
{
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<State> states(n, State::Unvisited);

    for (int node = 0; node < n; node++)
    {
      if (states[node] == State::Unvisited)
      {
        states[node] = getState(graph, states, node);
      }
    }

    vector<int> answer;
    for (int node = 0; node < n; node++)
    {
      if (states[node] == State::Safe)
      {
        answer.push_back(node);
      }
    }

    return answer;
  }

private:
  State getState(vector<vector<int>> &graph, vector<State> &states, int node)
  {
    if (states[node] == State::Current)
    {
      states[node] = State::Unsafe;
      return State::Unsafe;
    }

    if (states[node] != State::Unvisited)
    {
      return states[node];
    }

    if (graph[node].size() == 0)
    {
      states[node] = State::Safe;
      return State::Safe;
    }

    states[node] = State::Current;

    for (int next : graph[node])
    {
      if (states[next] == State::Unsafe)
      {
        states[node] = State::Unsafe;
        return State::Unsafe;
      }

      State nextState = getState(graph, states, next);
      if (nextState == State::Unsafe)
      {
        states[node] = State::Unsafe;
        return State::Unsafe;
      }
    }

    states[node] = State::Safe;
    return State::Safe;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.eventualSafeNodes(*new vector<vector<int>>{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}});
  auto result2 = solution.eventualSafeNodes(*new vector<vector<int>>{{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}});
}