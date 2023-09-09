// https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=daily-question&envId=2023-09-07
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
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    ListNode *beforeStart = nullptr;
    ListNode *start = head;
    ListNode *beforeEnd = nullptr;
    ListNode *end = head;
    stack<ListNode *> nextEnds;

    for (int i = 1; i < right; i++)
    {
      if (i < left)
      {
        beforeStart = start;
        start = start->next;
      }
      else
      {
        nextEnds.push(end);
      }
      beforeEnd = end;
      end = end->next;
    }

    while (left < right)
    {
      auto nextStart = start->next;
      auto nextEnd = end->next;
      if (beforeStart == nullptr)
      {
        head = end;
      }
      else
      {
        beforeStart->next = end;
      }

      if (right - left == 1)
      {
        if (beforeStart == nullptr)
        {
          head->next = start;
          head->next->next = nextEnd;
        }
        else
        {
          beforeStart->next->next = start;
          beforeStart->next->next->next = nextEnd;
        }

        return head;
      }

      left++;
      right--;

      end->next = start->next;
      beforeEnd->next = start;
      beforeEnd->next->next = nextEnd;

      beforeStart = end;
      start = nextStart;
      end = nextEnds.top();
      nextEnds.pop();
      beforeEnd = nextEnds.top();
    }

    return head;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.reverseBetween(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 2, 4);
  auto result2 = solution.reverseBetween(new ListNode(5), 1, 1);
  auto result3 = solution.reverseBetween(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 1, 5);
  auto result4 = solution.reverseBetween(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))), 1, 4);
  auto result5 = solution.reverseBetween(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))), 2, 3);
  auto result6 = solution.reverseBetween(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))), 1, 2);
  auto result7 = solution.reverseBetween(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))), 5, 6);
}