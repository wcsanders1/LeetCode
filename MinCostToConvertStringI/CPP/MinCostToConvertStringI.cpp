// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2026-01-29
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
  {
    int n = original.size();
    unordered_map<char, vector<pair<char, int>>> graph;
    for (int i = 0; i < n; i++)
    {
      graph[original[i]].push_back({changed[i], cost[i]});
    }

    long long total = 0;
    unordered_map<char, unordered_map<char, long long>> mem;
    for (int i = 0; i < source.size(); i++)
    {
      long long nextCost = getShortestPath(graph, source[i], target[i], mem);
      if (nextCost == -1)
      {
        return -1;
      }
      total += nextCost;
    }

    return total;
  }

private:
  long long getShortestPath(unordered_map<char, vector<pair<char, int>>> &graph, char source, char target, unordered_map<char, unordered_map<char, long long>> &mem)
  {
    if (source == target)
    {
      return 0;
    }

    if (mem.find(source) != mem.end() && mem[source].find(target) != mem[source].end())
    {
      return mem[source][target];
    }
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    unordered_set<char> visited;
    unordered_map<char, long long> costs;
    pq.push({0, source});
    costs[source] = 0;
    while (!pq.empty())
    {
      auto cur = pq.top();
      pq.pop();
      int curCost = cur.first;
      long long curNode = cur.second;
      if (visited.find(curNode) != visited.end())
      {
        continue;
      }

      visited.insert(curNode);
      for (auto &neighbor : graph[curNode])
      {
        char nextNode = neighbor.first;
        long long nextCost = neighbor.second + curCost;
        if (costs.find(nextNode) == costs.end())
        {
          costs[nextNode] = INT64_MAX;
        }

        if (nextCost < costs[nextNode])
        {
          costs[nextNode] = nextCost;
          pq.push({nextCost, nextNode});
        }
      }
    }

    long long a = costs.find(target) != costs.end() ? costs[target] : -1;
    mem[source][target] = a;
    return a;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.minimumCost("abcd", "acbe", *new vector<char>{'a', 'b', 'c', 'c', 'e', 'd'}, *new vector<char>{'b', 'c', 'b', 'e', 'b', 'e'}, *new vector<int>{2, 5, 5, 1, 2, 20});
  auto result2 = solution.minimumCost("aaaa", "bbbb", *new vector<char>{'a', 'c'}, *new vector<char>{'c', 'b'}, *new vector<int>{1, 2});
  auto result3 = solution.minimumCost("abcd", "abce", *new vector<char>{'a'}, *new vector<char>{'e'}, *new vector<int>{10000});
}