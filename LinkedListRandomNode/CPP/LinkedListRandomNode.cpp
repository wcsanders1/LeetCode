// https://leetcode.com/problems/linked-list-random-node/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

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
  vector<int> nodes;

  Solution(ListNode *head)
  {
    while (head != nullptr)
    {
      nodes.push_back(head->val);
      head = head->next;
    }
  }

  int getRandom()
  {
    int r = (nodes.size()) * (rand() / (RAND_MAX + 1.0));

    return nodes[r];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main()
{

  auto listNode = new ListNode(1, new ListNode(2, new ListNode(3)));
  auto solution = new Solution(listNode);
  int result1 = solution->getRandom();
  int result2 = solution->getRandom();
  int result3 = solution->getRandom();
  int result4 = solution->getRandom();
  int result5 = solution->getRandom();
}