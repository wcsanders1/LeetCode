// https://leetcode.com/problems/merge-k-sorted-lists/description/
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

class Sorter
{
public:
  bool operator()(ListNode *n1, ListNode *n2)
  {
    return n1->val >= n2->val;
  }
};

class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    priority_queue<ListNode *, vector<ListNode *>, Sorter> pq;
    for (auto node : lists)
    {
      if (node != nullptr)
      {
        pq.push(node);
      }
    }

    ListNode *head = nullptr;
    ListNode *cur = head;
    while (!pq.empty())
    {
      auto next = pq.top();
      auto nextNode = new ListNode(next->val);
      pq.pop();
      if (head == nullptr)
      {
        head = nextNode;
        cur = head;
      }
      else
      {
        cur->next = nextNode;
        cur = cur->next;
      }

      if (next->next != nullptr)
      {
        pq.push(next->next);
      }
    }

    return head;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.mergeKLists(*new vector<ListNode *>{new ListNode(1, new ListNode(4, new ListNode(5))), new ListNode(1, new ListNode(3, new ListNode(4))), new ListNode(2, new ListNode(6))});
  auto result2 = solution.mergeKLists(*new vector<ListNode *>{});
  auto result3 = solution.mergeKLists(*new vector<ListNode *>{nullptr});
}