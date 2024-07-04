// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04
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
  ListNode *mergeNodes(ListNode *head)
  {
    ListNode *lastZero = head;
    ListNode *current = head->next;
    int total = 0;
    while (current != nullptr)
    {
      if (current->val == 0)
      {
        lastZero->val = total;
        lastZero->next = current->next == nullptr ? nullptr : current;
        lastZero = current;
        total = 0;
      }
      else
      {
        total += current->val;
      }

      current = current->next;
    }

    return head;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.mergeNodes(new ListNode(0, new ListNode(3, new ListNode(1, new ListNode(0, new ListNode(4, new ListNode(5, new ListNode(2, new ListNode(0)))))))));
  auto result2 = solution.mergeNodes(new ListNode(0, new ListNode(1, new ListNode(0, new ListNode(3, new ListNode(0, new ListNode(2, new ListNode(2, new ListNode(0)))))))));
}