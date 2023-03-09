// https://leetcode.com/problems/linked-list-cycle-ii/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

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
  ListNode *detectCycle(ListNode *head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }

    auto step1 = head;
    auto step2 = head;

    do
    {
      step1 = step1->next;
      if (step1 == nullptr || step2->next == nullptr)
      {
        return nullptr;
      }

      step2 = step2->next->next;
      if (step2 == nullptr)
      {
        return nullptr;
      }

    } while (step1 != step2);

    step1 = head;
    while (step1 != step2)
    {
      step1 = step1->next;
      step2 = step2->next;
    }

    return step1;
  }
};

int main()
{
  Solution solution;

  auto link1_3 = new ListNode(3);
  auto link1_2 = new ListNode(2);
  auto link1_0 = new ListNode(0);
  auto link1_4 = new ListNode(-4);
  link1_3->next = link1_2;
  link1_2->next = link1_0;
  link1_0->next = link1_4;
  link1_4->next = link1_2;
  auto result1 = solution.detectCycle(link1_3);
}