// https://leetcode.com/problems/clone-graph/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Node
{
public:
  int val;
  vector<Node *> neighbors;
  Node()
  {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution
{
public:
  Node *cloneGraph(Node *node)
  {
    if (node == nullptr)
    {
      return nullptr;
    }

    unordered_map<int, Node *> nodes;
    Node *newNode = new Node(node->val);
    clone(node, newNode, nodes);
    return newNode;
  }

private:
  void clone(Node *node, Node *newNode, unordered_map<int, Node *> &nodes)
  {
    if (node == nullptr || newNode == nullptr)
    {
      return;
    }

    nodes[newNode->val] = newNode;

    for (Node *next : node->neighbors)
    {
      if (nodes.find(next->val) != nodes.end())
      {
        newNode->neighbors.push_back(nodes[next->val]);
      }
      else
      {
        Node *nextNew = new Node(next->val);
        newNode->neighbors.push_back(nextNew);
        clone(next, nextNew, nodes);
      }
    }
  }
};

int main()
{
  Solution solution;

  auto node1 = new Node(1);
  auto node2 = new Node(2);
  auto node3 = new Node(3);
  auto node4 = new Node(4);
  node1->neighbors = {node2, node4};
  node2->neighbors = {node1, node3};
  node3->neighbors = {node2, node4};
  node4->neighbors = {node1, node3};
  auto result1 = solution.cloneGraph(node1);
}