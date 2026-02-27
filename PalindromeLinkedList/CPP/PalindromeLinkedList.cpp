// https://leetcode.com/problems/palindrome-linked-list/description/
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
  bool isPalindrome(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return true;
    }

    auto end = head;
    auto half = head;
    int count = 0;
    while (end != nullptr && end->next != nullptr)
    {
      count++;
      half = half->next;
      end = end->next->next;
    }

    bool isOdd = end != nullptr;
    auto cur = head;
    ListNode *prev = nullptr;
    while (count-- > 0)
    {
      auto next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    if (isOdd)
    {
      half = half->next;
    }

    while (half != nullptr)
    {
      if (prev->val != half->val)
      {
        return false;
      }

      prev = prev->next;
      half = half->next;
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1)))));
  bool result2 = solution.isPalindrome(new ListNode(1, new ListNode(2)));
  bool result3 = solution.isPalindrome(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(1))))));
}