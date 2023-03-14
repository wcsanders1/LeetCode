// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

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
  int sumNumbers(TreeNode *root)
  {
    vector<int> nums;
    getNums(root, 0, nums);
    int answer = 0;
    for (int n : nums)
    {
      answer += n;
    }

    return answer;
  }

private:
  void getNums(TreeNode *node, int curNum, vector<int> &nums)
  {
    if (node == nullptr)
    {
      return;
    }

    curNum = (curNum * 10) + node->val;
    if (node->left == nullptr && node->right == nullptr)
    {
      nums.push_back(curNum);
      return;
    }

    getNums(node->left, curNum, nums);
    getNums(node->right, curNum, nums);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.sumNumbers(new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0)));
}