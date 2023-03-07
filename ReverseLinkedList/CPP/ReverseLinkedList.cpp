//
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
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
  ListNode *reverseList(ListNode *head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }

    auto temp = head->next;
    auto h = head;
    h->next = nullptr;
    while (temp != nullptr)
    {
      auto t = temp->next;
      temp->next = h;
      h = temp;
      temp = t;
    }

    return h;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.reverseList(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))));
}