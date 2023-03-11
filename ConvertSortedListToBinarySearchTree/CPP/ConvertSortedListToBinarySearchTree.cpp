// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
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

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  TreeNode *sortedListToBST(ListNode *head)
  {
    vector<int> nums;
    auto node = head;
    while (node != nullptr)
    {
      nums.push_back(node->val);
      node = node->next;
    }

    return buildTree(nums, 0, nums.size() - 1);
  }

private:
  TreeNode *buildTree(vector<int> &nums, int start, int end)
  {
    if (start > end)
    {
      return nullptr;
    }

    if (start == end)
    {
      return new TreeNode(nums[start]);
    }

    if ((end - start) == 1)
    {
      return new TreeNode(nums[end], new TreeNode(nums[start]), nullptr);
    }

    int mid = (end + start) / 2;

    auto left = buildTree(nums, start, mid - 1);
    auto right = buildTree(nums, mid + 1, end);

    return new TreeNode(nums[mid], left, right);
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.sortedListToBST(new ListNode(-10, new ListNode(-3, new ListNode(0, new ListNode(5, new ListNode(9))))));
  auto result2 = solution.sortedListToBST(nullptr);
}