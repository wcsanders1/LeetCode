// https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23
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

    reorder(head, head);
  }

private:
  ListNode *reorder(ListNode *start, ListNode *end)
  {
    if (end == nullptr)
    {
      return start;
    }

    ListNode *cur = reorder(start, end->next);

    if (cur != nullptr && cur->next != nullptr && cur->next->next != nullptr)
    {
      ListNode *temp = cur->next;
      while (temp->next != nullptr)
      {
        temp = temp->next;
      }

      end = temp;

      ListNode *t = cur->next;
      cur->next = end;
      cur->next->next = t;

      while (t->next != end)
      {
        t = t->next;
      }

      t->next = nullptr;
    }

    return (cur == nullptr || cur->next == nullptr) ? nullptr : cur->next->next;
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