// https://leetcode.com/problems/copy-list-with-random-pointer/?envType=daily-question&envId=2023-09-05
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }

    vector<Node *> new_nodes;
    unordered_map<Node *, int> node_map;
    Node *cur_new_node = nullptr;
    auto cur_node = head;
    int index = 0;

    while (cur_node != nullptr)
    {
      if (cur_new_node == nullptr)
      {
        cur_new_node = new Node(cur_node->val);
        new_nodes.push_back(cur_new_node);
      }
      else
      {
        cur_new_node->next = new Node(cur_node->val);
        new_nodes.push_back(cur_new_node->next);
        cur_new_node = cur_new_node->next;
      }

      node_map[cur_node] = index++;
      cur_node = cur_node->next;
    }

    cur_node = head;
    index = 0;
    while (cur_node != nullptr)
    {
      if (cur_node->random != nullptr)
      {
        new_nodes[index]->random = new_nodes[node_map[cur_node->random]];
      }
      index++;
      cur_node = cur_node->next;
    }

    return new_nodes[0];
  }
};

int main()
{
  Solution solution;

  auto node1 = new Node(7);
  auto node2 = new Node(13);
  auto node3 = new Node(11);
  auto node4 = new Node(10);
  auto node5 = new Node(1);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node2->random = node1;
  node3->random = node5;
  node4->random = node3;
  node5->random = node1;

  auto result1 = solution.copyRandomList(node1);
}