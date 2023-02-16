// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/
#include <vector>
#include <unordered_map>

using namespace std;

struct Tracker
{
  int passengers;
  long long distanceTraveled;
  Tracker() : passengers(1), distanceTraveled(0) {}
};

class Solution
{
public:
  long long minimumFuelCost(vector<vector<int>> &roads, int seats)
  {
    unordered_map<int, vector<int>> graph;
    for (vector<int> road : roads)
    {
      if (graph.count(road[0]) == 0)
      {
        graph[road[0]] = vector<int>();
      }

      if (graph.count(road[1]) == 0)
      {
        graph[road[1]] = vector<int>();
      }

      graph[road[0]].push_back(road[1]);
      graph[road[1]].push_back(road[0]);
    }

    vector<bool> visited(roads.size() + 1, false);

    auto tracker = getDistance(graph, visited, 0, seats);

    return tracker.distanceTraveled;
  }

private:
  Tracker getDistance(unordered_map<int, vector<int>> &graph, vector<bool> &visited, int road, int seats)
  {
    visited[road] = true;
    Tracker tracker;
    for (int r : graph[road])
    {
      if (!visited[r])
      {
        visited[r] = true;
        Tracker t = getDistance(graph, visited, r, seats);
        tracker.passengers += t.passengers;
        long long d = ceil((double)t.passengers / (double)seats);
        tracker.distanceTraveled += (t.distanceTraveled) + (d == 0 ? t.passengers : d);
      }
    }

    return tracker;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumFuelCost(*new vector<vector<int>>{{0, 1}, {0, 2}, {0, 3}}, 5);                                 // 3
  int result2 = solution.minimumFuelCost(*new vector<vector<int>>{{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}}, 2);         // 7
  int result3 = solution.minimumFuelCost(*new vector<vector<int>>(), 1);                                                       // 0
  int result4 = solution.minimumFuelCost(*new vector<vector<int>>{{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}, {4, 7}}, 2); // 9
  int result5 = solution.minimumFuelCost(*new vector<vector<int>>{{1, 0}, {0, 2}, {3, 1}, {1, 4}, {5, 0}}, 1);                 // 7
}