// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
#include <vector>
#include <unordered_set>
#include <queue>
#include <numeric>

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
  ListNode *insertGreatestCommonDivisors(ListNode *head)
  {
    auto current = head;
    while (current != nullptr && current->next != nullptr)
    {
      auto nextCurrent = current->next;
      int num1 = current->val;
      int num2 = current->next->val;
      auto newNode = new ListNode(gcd(num1, num2), current->next);
      current->next = newNode;
      current = nextCurrent;
    }

    return head;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.insertGreatestCommonDivisors(new ListNode(18, new ListNode(6, new ListNode(10, new ListNode(3)))));
  auto result2 = solution.insertGreatestCommonDivisors(new ListNode(7));
}