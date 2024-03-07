// https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07
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
  ListNode *middleNode(ListNode *head)
  {
    int count = 0;
    ListNode *cur = head;
    while (cur != nullptr)
    {
      cur = cur->next;
      count++;
    }

    int mid = (count / 2) + 1;
    cur = head;
    while (--mid > 0)
    {
      cur = cur->next;
    }

    return cur;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.middleNode(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))));
  auto result2 = solution.middleNode(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
  auto result3 = solution.middleNode(new ListNode(1));
  auto result4 = solution.middleNode(new ListNode(1, new ListNode(2)));
}