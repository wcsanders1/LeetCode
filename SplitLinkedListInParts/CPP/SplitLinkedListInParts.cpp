// https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2023-09-06
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
  vector<ListNode *> splitListToParts(ListNode *head, int k)
  {
    int count = 0;
    ListNode *current = head;
    while (current != nullptr)
    {
      count++;
      current = current->next;
    }

    int amount = 0;
    int extra = 0;
    if (k > count)
    {
      amount = 0;
      extra = count;
    }
    else
    {
      amount = count / k;
      extra = count % k;
    }

    vector<ListNode *> splits;
    current = head;
    while (k-- > 0)
    {
      ListNode *nextHead = nullptr;
      for (int i = 0; i < amount; i++)
      {
        if (nextHead == nullptr)
        {
          nextHead = current;
          splits.push_back(nextHead);
        }
        else
        {
          nextHead->next = current;
          nextHead = nextHead->next;
        }
        current = current->next;
      }

      if (extra > 0)
      {
        extra--;
        if (nextHead == nullptr)
        {
          nextHead = current;
          splits.push_back(nextHead);
        }
        else
        {
          nextHead->next = current;
          nextHead = nextHead->next;
        }
        current = current->next;
      }

      if (nextHead != nullptr)
      {
        nextHead->next = nullptr;
      }
      else
      {
        splits.push_back(nullptr);
      }
    }

    return splits;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.splitListToParts(new ListNode(1, new ListNode(2, new ListNode(3))), 5);
  auto result2 = solution.splitListToParts(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7, new ListNode(8, new ListNode(9, new ListNode(10)))))))))), 3);
}