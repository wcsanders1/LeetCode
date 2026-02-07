// https://leetcode.com/problems/insertion-sort-list/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

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
  ListNode *insertionSortList(ListNode *head)
  {
    return order(head);
  }

private:
  ListNode *order(ListNode *node)
  {
    if (node == nullptr || node->next == nullptr)
    {
      return node;
    }

    node->next = order(node->next);

    if (node->val <= node->next->val)
    {
      return node;
    }

    auto n = node->next;
    ListNode *prev = nullptr;
    while (node->next != nullptr && node->val > node->next->val)
    {
      auto t = node->next;
      node->next = node->next->next;
      t->next = node;
      if (prev != nullptr)
      {
        prev->next = t;
      }
      prev = t;
    }

    return n;
  }
};

int main()
{
  Solution solution;
  auto result1 = solution.insertionSortList(new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3)))));
  auto result2 = solution.insertionSortList(new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0))))));
}