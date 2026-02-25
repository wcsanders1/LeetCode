// https://leetcode.com/problems/intersection-of-two-linked-lists/description/
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
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    int lenA = 0;
    int lenB = 0;
    auto curA = headA;
    auto curB = headB;
    while (curA != nullptr || curB != nullptr)
    {
      if (curA != nullptr)
      {
        lenA++;
        curA = curA->next;
      }

      if (curB != nullptr)
      {
        lenB++;
        curB = curB->next;
      }
    }

    curA = headA;
    curB = headB;

    if (lenA > lenB)
    {
      for (int i = lenA - lenB; i > 0; i--)
      {
        curA = curA->next;
      }
    }
    else
    {
      for (int i = lenB - lenA; i > 0; i--)
      {
        curB = curB->next;
      }
    }

    while (curA != nullptr && curB != nullptr)
    {
      if (curA == curB)
      {
        return curA;
      }

      curA = curA->next;
      curB = curB->next;
    }

    return nullptr;
  }
};