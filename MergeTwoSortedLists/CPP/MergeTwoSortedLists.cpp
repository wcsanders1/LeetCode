// https://leetcode.com/problems/merge-two-sorted-lists/description/
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode *merged = nullptr;
    ListNode *current = nullptr;
    while (list1 != nullptr || list2 != nullptr)
    {
      ListNode *next = nullptr;
      if (list1 == nullptr)
      {
        next = new ListNode(list2->val);
        list2 = list2->next;
      }
      else if (list2 == nullptr)
      {
        next = new ListNode(list1->val);
        list1 = list1->next;
      }
      else if (list1->val < list2->val)
      {
        next = new ListNode(list1->val);
        list1 = list1->next;
      }
      else
      {
        next = new ListNode(list2->val);
        list2 = list2->next;
      }

      if (merged == nullptr)
      {
        merged = next;
        current = next;
      }
      else
      {
        current->next = next;
        current = current->next;
      }
    }

    return merged;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.mergeTwoLists(new ListNode(1, new ListNode(2, new ListNode(4))), new ListNode(1, new ListNode(3, new ListNode(4))));
  auto result2 = solution.mergeTwoLists(nullptr, nullptr);
  auto result3 = solution.mergeTwoLists(nullptr, new ListNode(0));
}