// https://leetcode.com/problems/longest-consecutive-sequence/
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
  int root;
  int value;
  int count;
  bool visited;
  Node(int v) : root(v), value(v), count(1), visited(false) {}
};

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    if (nums.size() == 0)
    {
      return 0;
    }

    unordered_map<int, Node *> graph;
    for (int num : nums)
    {
      if (graph.find(num) == graph.end())
      {
        graph[num] = new Node(num);
      }
    }

    for (int num : nums)
    {
      if (graph.find(num - 1) != graph.end())
      {
        graph[num]->root = num - 1;
      }
    }

    int answer = 1;
    for (int num : nums)
    {
      int count = getCount(graph, graph[num]);
      answer = max(answer, count);
    }

    return answer;
  }

private:
  int getCount(unordered_map<int, Node *> &graph, Node *node)
  {
    if (node->root == node->value)
    {
      node->count = 1;
      node->visited = true;
    }

    if (node->visited)
    {
      return node->count;
    }

    node->count += getCount(graph, graph[node->root]);
    node->visited = true;
    return node->count;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestConsecutive(*new vector<int>{100, 4, 200, 1, 3, 2});
  int result2 = solution.longestConsecutive(*new vector<int>{0, 3, 7, 2, 5, 8, 4, 6, 0, 1});
  int result3 = solution.longestConsecutive(*new vector<int>{0, 1, 2, 4, 8, 5, 6, 7, 9, 3, 55, 88, 77, 99, 999999999});
}