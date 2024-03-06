// https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06
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
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    if (head == nullptr)
    {
      return false;
    }

    ListNode *start = head;
    ListNode *end = head->next;

    while (start != nullptr && end != nullptr)
    {
      if (start == end)
      {
        return true;
      }

      start = start->next;
      end = end->next == nullptr ? nullptr : end->next->next;
    }

    return false;
  }
};