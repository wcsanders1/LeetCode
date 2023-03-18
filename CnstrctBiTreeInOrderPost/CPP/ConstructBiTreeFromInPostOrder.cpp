// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
#include <vector>
#include <unordered_map>
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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    return buildTree(inorder, postorder, 0, postorder.size() - 1, 0, postorder.size() - 1);
  }

private:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int ileft, int iright, int pleft, int pright)
  {
    if (ileft > iright)
    {
      return nullptr;
    }

    if (ileft == iright)
    {
      return new TreeNode(inorder[ileft]);
    }

    int imid = ileft;
    while (inorder[imid] != postorder[pright])
    {
      imid++;
    }

    int pmid = pleft + imid - ileft;

    auto leftNode = buildTree(inorder, postorder, ileft, imid - 1, pleft, pmid - 1);
    auto rightNode = buildTree(inorder, postorder, imid + 1, iright, pmid, pright - 1);

    return new TreeNode(postorder[pright], leftNode, rightNode);
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.buildTree(*new vector<int>{9, 3, 15, 20, 7}, *new vector<int>{9, 15, 7, 20, 3});
  auto result2 = solution.buildTree(*new vector<int>{-1}, *new vector<int>{-1});
  auto result3 = solution.buildTree(*new vector<int>{4, 9, 5, 3, 15, 20, 7}, *new vector<int>{4, 5, 9, 15, 7, 20, 3});
  auto result4 = solution.buildTree(*new vector<int>{1, 2, 3, 4}, *new vector<int>{3, 2, 4, 1});
}