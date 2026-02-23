// https://leetcode.com/problems/odd-even-linked-list/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

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
  ListNode *oddEvenList(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
    {
      return head;
    }

    auto cur = head;
    auto next = head->next->next;
    ListNode *prev = nullptr;

    while (next != nullptr)
    {
      auto nextnext = next->next;
      auto t = cur->next;
      cur->next = next;
      next->next = t;
      if (prev != nullptr)
      {
        prev->next = nextnext;
      }
      else
      {
        t->next = nextnext;
      }
      prev = nextnext;
      next = nextnext == nullptr ? nullptr : nextnext->next;
      cur = cur->next;
    }

    return head;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.oddEvenList(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))));
  auto result2 = solution.oddEvenList(new ListNode(2, new ListNode(1, new ListNode(3, new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(7))))))));
}