// https://leetcode.com/problems/find-all-people-with-secret/description/?envType=daily-question&envId=2024-02-24
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Compare
{
public:
  bool operator()(vector<int> &a, vector<int> &b)
  {
    return a[1] < b[1];
  }
};

class Solution
{
public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
  {

    unordered_map<int, priority_queue<vector<int>, vector<vector<int>>, Compare>> graph;

    for (int i = 0; i < meetings.size(); i++)
    {
      auto &m = meetings[i];
      graph[m[0]].push({i, m[2]});
      graph[m[1]].push({i, m[2]});
    }

    vector<bool> visited(meetings.size(), false);
    vector<bool> hasSecret(n + 1, false);
    hasSecret[0] = true;
    hasSecret[firstPerson] = true;

    while (!graph[0].empty())
    {
      auto &next = graph[0].top();
      int nextMeeting = next[0];
      int nextTime = next[1];
      graph[0].pop();
      getPeopleWithSecrets(meetings, graph, visited, nextMeeting, nextTime, hasSecret);
    }

    while (!graph[firstPerson].empty())
    {
      auto &next = graph[firstPerson].top();
      int nextMeeting = next[0];
      int nextTime = next[1];
      graph[firstPerson].pop();
      getPeopleWithSecrets(meetings, graph, visited, nextMeeting, nextTime, hasSecret);
    }

    vector<int> answer;

    for (int i = 0; i <= n; i++)
    {
      if (hasSecret[i])
      {
        answer.push_back(i);
      }
    }

    return answer;
  }

private:
  void getPeopleWithSecrets(vector<vector<int>> &meetings, unordered_map<int, priority_queue<vector<int>, vector<vector<int>>, Compare>> &graph, vector<bool> &visited, int curMeeting, int minTime, vector<bool> &hasSecret)
  {
    if (visited[curMeeting])
    {
      return;
    }

    visited[curMeeting] = true;
    auto &m = meetings[curMeeting];
    hasSecret[m[0]] = true;
    hasSecret[m[1]] = true;

    while (!graph[m[0]].empty() && graph[m[0]].top()[1] >= minTime)
    {
      auto &next = graph[m[0]].top();
      int nextMeeting = next[0];
      int nextTime = next[1];
      graph[m[0]].pop();
      getPeopleWithSecrets(meetings, graph, visited, nextMeeting, nextTime, hasSecret);
    }

    while (!graph[m[1]].empty() && graph[m[1]].top()[1] >= minTime)
    {
      auto &next = graph[m[1]].top();
      int nextMeeting = next[0];
      int nextTime = next[1];
      graph[m[1]].pop();
      getPeopleWithSecrets(meetings, graph, visited, nextMeeting, nextTime, hasSecret);
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findAllPeople(6, *new vector<vector<int>>{{1, 2, 5}, {2, 3, 8}, {1, 5, 10}}, 1); // [0, 1, 2, 3, 5]
  auto result2 = solution.findAllPeople(4, *new vector<vector<int>>{{3, 1, 3}, {1, 2, 2}, {0, 3, 3}}, 3);  // [0, 1, 3]
  auto result3 = solution.findAllPeople(6, *new vector<vector<int>>{{3, 4, 2}, {1, 2, 1}, {2, 3, 1}}, 1);  // [0, 1, 2, 3, 4]
  auto result4 = solution.findAllPeople(6, *new vector<vector<int>>{{0, 2, 1}, {1, 3, 1}, {4, 5, 1}}, 1);  // [0, 1, 2, 3]
  auto result5 = solution.findAllPeople(5, *new vector<vector<int>>{{1, 4, 3}, {0, 4, 3}}, 3);             // [0, 1, 3, 4]
  auto result6 = solution.findAllPeople(12, *new vector<vector<int>>{{10, 8, 6}, {9, 5, 11}, {0, 5, 18}, {4, 5, 13}, {11, 6, 17}, {0, 11, 10}, {10, 11, 7}, {5, 8, 3}, {7, 6, 16}, {3, 6, 10}, {3, 11, 1}, {8, 3, 2}, {5, 0, 7}, {3, 8, 20}, {11, 0, 20}, {8, 3, 4}, {1, 9, 4}, {10, 7, 11}, {8, 10, 18}},
                                        9); // [0, 1, 4, 5, 6, 9, 11]
}