// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    int cur = removeNode(head, n);
    if (cur == n)
    {
      return head->next;
    }

    return head;
  }

private:
  int removeNode(ListNode *node, int n)
  {
    if (node == nullptr)
    {
      return 0;
    }

    int cur = removeNode(node->next, n);

    if (cur == n)
    {
      if (node->next == nullptr)
      {
        node = nullptr;
      }
      else
      {
        node->next = node->next->next;
      }
    }

    return cur + 1;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.removeNthFromEnd(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 2);
  auto result2 = solution.removeNthFromEnd(new ListNode(1), 1);
  auto result3 = solution.removeNthFromEnd(new ListNode(1, new ListNode(2)), 1);
  auto result4 = solution.removeNthFromEnd(new ListNode(1, new ListNode(2)), 2);
}