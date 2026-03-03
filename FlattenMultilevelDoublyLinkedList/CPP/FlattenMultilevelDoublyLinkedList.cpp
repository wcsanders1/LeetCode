// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Node
{
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution
{
public:
  Node *flatten(Node *head)
  {
    Node *cur = head;
    while (cur != nullptr)
    {
      auto next = cur->next;
      if (cur->child != nullptr)
      {
        auto n = flatten(cur->child);
        cur->child = nullptr;
        cur->next = n;
        n->prev = cur;
        auto t = n;
        while (t->next != nullptr)
        {
          t = t->next;
        }

        if (t != next)
        {
          t->next = next;
        }

        if (next != nullptr)
        {
          next->prev = t;
        }
      }

      cur = next;
    }

    return head;
  }
};

int main()
{
  Solution solution;

  auto node1 = new Node();
  node1->val = 1;
  auto node2 = new Node();
  node2->val = 2;
  auto node3 = new Node();
  node3->val = 3;
  auto node4 = new Node();
  node4->val = 4;
  auto node5 = new Node();
  node5->val = 5;
  auto node6 = new Node();
  node6->val = 6;
  auto node7 = new Node();
  node7->val = 7;
  auto node8 = new Node();
  node8->val = 8;
  auto node9 = new Node();
  node9->val = 9;
  auto node10 = new Node();
  node10->val = 10;
  auto node11 = new Node();
  node11->val = 11;
  auto node12 = new Node();
  node12->val = 12;
  node1->next = node2;
  node2->prev = node1;
  node2->next = node3;
  node3->prev = node2;
  node3->next = node4;
  node4->prev = node3;
  node4->next = node5;
  node5->prev = node4;
  node5->next = node6;
  node6->prev = node5;
  node7->next = node8;
  node8->prev = node7;
  node8->next = node9;
  node9->prev = node8;
  node9->next = node10;
  node10->prev = node9;
  node11->next = node12;
  node12->prev = node11;
  node3->child = node7;
  node8->child = node11;
  auto result1 = solution.flatten(node1);

  auto nodeb1 = new Node();
  nodeb1->val = 1;
  auto nodeb2 = new Node();
  nodeb2->val = 2;
  auto nodeb3 = new Node();
  nodeb3->val = 3;
  nodeb1->child = nodeb2;
  nodeb2->child = nodeb3;
  auto result2 = solution.flatten(nodeb1);
}