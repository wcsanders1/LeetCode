// https://leetcode.com/problems/reorder-list/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  void reorderList(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return;
    }

    stack<ListNode *> s;
    auto cur = head;
    while (cur != nullptr)
    {
      s.push(cur);
      cur = cur->next;
    }

    cur = head;
    while (s.top() != cur)
    {
      auto t = cur->next;
      auto n = s.top();
      s.pop();
      n->next = nullptr;
      if (t == n)
      {
        return;
      }
      cur->next = n;
      cur->next->next = t;
      cur = t;
    }
    cur->next = nullptr;
  }
};

int main()
{
  Solution solution;

  ListNode *n1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  solution.reorderList(n1);
  ListNode *n2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  solution.reorderList(n2);
  ListNode *n3 = new ListNode(1, new ListNode(2, new ListNode(3)));
  solution.reorderList(n3);
  ListNode *n4 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
  solution.reorderList(n4);
}