// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maximumInvitations(vector<int> &favorite)
  {
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < favorite.size(); i++)
    {
      if (graph.find(favorite[i]) == graph.end())
      {
        graph[favorite[i]] = vector<int>();
      }

      graph[favorite[i]].push_back(i);
    }

    vector<int> maxCache(favorite.size(), 0);
    }
};