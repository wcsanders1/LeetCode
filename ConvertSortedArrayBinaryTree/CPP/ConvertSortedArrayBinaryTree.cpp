// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
#include <vector>
#include <queue>

using namespace std;

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
  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    TreeNode *root = getNode(nums, 0, nums.size());
    return root;
  }

private:
  TreeNode *getNode(vector<int> &nums, int start, int end)
  {
    if (start > end)
    {
      return nullptr;
    }

    int mid = (start + end) / 2;
    if (mid < 0 || mid >= nums.size())
    {
      return nullptr;
    }

    TreeNode *node = new TreeNode(nums[mid]);
    node->left = getNode(nums, start, mid - 1);
    node->right = getNode(nums, mid + 1, end);

    return node;
  }
};

int main()
{
  Solution solution;

  TreeNode *result1 = solution.sortedArrayToBST(vector<int>{-10, -3, 0, 5, 9});
  TreeNode *result2 = solution.sortedArrayToBST(vector<int>{1, 3});
  TreeNode *result3 = solution.sortedArrayToBST(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
}