// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2024-07-05
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

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
  vector<int> nodesBetweenCriticalPoints(ListNode *head)
  {
    stack<int> points;
    int prev = head->val;
    ListNode *currentNode = head->next;
    int currentIndex = 2;
    while (currentNode != nullptr && currentNode->next != nullptr)
    {
      if (currentNode->val < prev && currentNode->val < currentNode->next->val || currentNode->val > prev && currentNode->val > currentNode->next->val)
      {
        points.push(currentIndex);
      }

      prev = currentNode->val;
      currentNode = currentNode->next;
      currentIndex++;
    }

    int mn = INT32_MAX;
    int mx = INT32_MIN;
    int first = points.empty() ? 0 : points.top();
    while (points.size() > 1)
    {
      int a = points.top();
      points.pop();
      int b = points.top();
      mn = min(mn, a - b);
      mx = max(mx, first - b);
    }

    return vector<int>{mn == INT32_MAX ? -1 : mn, mx == INT32_MIN ? -1 : mx};
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.nodesBetweenCriticalPoints(new ListNode(3, new ListNode(1)));
  auto result2 = solution.nodesBetweenCriticalPoints(new ListNode(5, new ListNode(3, new ListNode(1, new ListNode(2, new ListNode(5, new ListNode(1, new ListNode(2))))))));
  auto result3 = solution.nodesBetweenCriticalPoints(new ListNode(1, new ListNode(3, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(2, new ListNode(2, new ListNode(7))))))))));
}