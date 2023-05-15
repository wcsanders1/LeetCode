// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
#include <vector>
#include <unordered_set>
#include <queue>

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
  ListNode *swapNodes(ListNode *head, int k)
  {
    ListNode *first = nullptr;
    int length = 1;
    ListNode *cur = head;

    while (cur != nullptr)
    {
      if (length == k)
      {
        first = cur;
      }

      cur = cur->next;
      if (cur != nullptr)
      {
        length++;
      }
    }

    cur = head;
    for (int i = 0; i < length - k; i++)
    {
      cur = cur->next;
    }

    int t = cur->val;
    cur->val = first->val;
    first->val = t;

    return head;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.swapNodes(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 2);
}