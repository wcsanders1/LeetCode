// https://leetcode.com/problems/add-two-numbers-ii/description/
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    stack<int> s1;
    stack<int> s2;
    auto cur1 = l1;
    auto cur2 = l2;
    while (cur1 != nullptr || cur2 != nullptr)
    {
      if (cur1 != nullptr)
      {
        s1.push(cur1->val);
        cur1 = cur1->next;
      }

      if (cur2 != nullptr)
      {
        s2.push(cur2->val);
        cur2 = cur2->next;
      }
    }

    int carry = 0;
    ListNode *answer = nullptr;
    ListNode *prev = nullptr;
    while (!s1.empty() || !s2.empty())
    {
      int i = carry;
      if (!s1.empty())
      {
        i += s1.top();
        s1.pop();
      }

      if (!s2.empty())
      {
        i += s2.top();
        s2.pop();
      }

      int n = i > 9 ? i - 10 : i;
      carry = i > 9 ? 1 : 0;
      answer = new ListNode(n);
      answer->next = prev;
      prev = answer;
    }

    if (carry > 0)
    {
      answer = new ListNode(carry);
      answer->next = prev;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.addTwoNumbers(new ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3)))), new ListNode(5, new ListNode(6, new ListNode(4))));
}