// https://leetcode.com/problems/longest-consecutive-sequence/
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
  int root;
  int value;
  Node(int v) : root(v), value(v) {}
};

class Union
{
public:
  void add(int value)
  {
    Node *node = new Node(value);
    if (groupsByRoot.find(value) == groupsByRoot.end())
    {
      groupsByRoot[value] = new vector<Node *>(1, node);
    }
    else
    {
      groupsByRoot[value]->push_back(node);
    }
  }

  void unify(int value1, int value2)
  {
    if (groupsByRoot.find(value1) == groupsByRoot.end() || groupsByRoot.find(value2) == groupsByRoot.end())
    {
      return;
    }

    for (Node *node : *groupsByRoot[value2])
    {
      groupsByRoot[value1]->push_back(node);
    }

    groupsByRoot.erase(value2);
  }

private:
  unordered_map<int, vector<Node *> *> groupsByRoot;
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
        graph[num]->root = graph[num - 1]->root;
      }
    }

    int answer = 1;
    for (int num : nums)
    {
      Node *node = graph[num];
      if (node->root == node->value)
      {
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  // int result1 = solution.longestConsecutive(*new vector<int>{100, 4, 200, 1, 3, 2});
  int result2 = solution.longestConsecutive(*new vector<int>{0, 3, 7, 2, 5, 8, 4, 6, 0, 1});
}