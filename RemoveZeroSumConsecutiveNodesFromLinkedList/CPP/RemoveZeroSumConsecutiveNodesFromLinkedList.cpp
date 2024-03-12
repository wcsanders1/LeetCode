// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/?envType=daily-question&envId=2024-03-12
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <tuple>

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
  ListNode *removeZeroSumSublists(ListNode *head)
  {
    bool canRemove = true;
    while (canRemove)
    {
      vector<ListNode *> nodes;
      vector<int> values;
      auto [removed, newHead] = removedSequence(head, nodes, values);
      canRemove = removed;
      head = newHead;
    }

    return head;
  }

private:
  tuple<bool, ListNode *> removedSequence(ListNode *head, vector<ListNode *> &nodes, vector<int> &values)
  {
    ListNode *cur = head;
    while (cur != nullptr)
    {
      if (cur->val == 0)
      {
        if (nodes.empty())
        {
          return {true, cur->next};
        }
        nodes[nodes.size() - 1]->next = cur->next;
        return {true, head};
      }

      nodes.push_back(cur);
      values.push_back(cur->val);
      for (int i = 0; i < nodes.size() - 1; i++)
      {
        values[i] += cur->val;
        if (values[i] == 0)
        {
          if (i > 0)
          {
            nodes[i - 1]->next = cur->next;
          }
          else
          {
            head = cur->next;
          }

          return {true, head};
        }
      }
      cur = cur->next;
    }

    return {false, head};
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.removeZeroSumSublists(new ListNode(1, new ListNode(2, new ListNode(-3, new ListNode(3, new ListNode(1))))));
  auto result2 = solution.removeZeroSumSublists(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(-3, new ListNode(4))))));
  auto result3 = solution.removeZeroSumSublists(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(-3, new ListNode(-2))))));
}