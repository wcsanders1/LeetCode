// https://leetcode.com/problems/remove-linked-list-elements/description/
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
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode *prev = nullptr;
    ListNode *cur = head;
    while (cur != nullptr)
    {
      if (cur->val == val)
      {
        if (prev == nullptr)
        {
          head = cur->next;
        }
        else
        {
          prev->next = cur->next;
        }
      }
      else
      {
        prev = cur;
      }
      cur = cur->next;
    }

    return head;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.removeElements(new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))))), 6);
  auto result2 = solution.removeElements(nullptr, 1);
  auto result3 = solution.removeElements(new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7)))), 7);
}