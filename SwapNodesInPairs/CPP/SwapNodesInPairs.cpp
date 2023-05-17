// https://leetcode.com/problems/swap-nodes-in-pairs/
// NOT MINE: https://leetcode.com/problems/swap-nodes-in-pairs/solutions/1774708/c-visual-image-how-links-change-explained-every-step-commented-code/
#include <vector>
#include <unordered_set>
#include <queue>

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
  ListNode *swapPairs(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }

    ListNode *temp = head->next;
    head->next = swapPairs(head->next->next);
    temp->next = head;
    return temp;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.swapPairs(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4)))));
}