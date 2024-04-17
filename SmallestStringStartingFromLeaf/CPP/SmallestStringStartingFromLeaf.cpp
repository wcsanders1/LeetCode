// https://leetcode.com/problems/smallest-string-starting-from-leaf/description/?envType=daily-question&envId=2024-04-17
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>

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
  string smallestFromLeaf(TreeNode *root)
  {
    string smallest = "";
    getSmallest(root, smallest, "");
    return smallest;
  }

private:
  void getSmallest(TreeNode *node, string &smallest, string current)
  {
    current.push_back(('a' + node->val));
    if (node->left == nullptr && node->right == nullptr)
    {
      reverse(current.begin(), current.end());
      if (current < smallest || smallest == "")
      {
        smallest = current;
      }
      return;
    }

    if (node->left != nullptr)
    {
      getSmallest(node->left, smallest, current);
    }

    if (node->right != nullptr)
    {
      getSmallest(node->right, smallest, current);
    }
  }
};

int main()
{
  Solution solution;

  string result1 = solution.smallestFromLeaf(new TreeNode(0, new TreeNode(1, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(3), new TreeNode(4))));
  string result2 = solution.smallestFromLeaf(new TreeNode(0, nullptr, new TreeNode(1)));
}