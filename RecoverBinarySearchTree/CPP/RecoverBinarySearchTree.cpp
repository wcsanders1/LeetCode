// https://leetcode.com/problems/recover-binary-search-tree/description/
#include <queue>
#include <vector>
#include <set>

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

auto cmp = [](TreeNode *n1, TreeNode *n2)
{
  return n1->val > n2->val;
};

class Solution
{
public:
  void recoverTree(TreeNode *root)
  {

    set<TreeNode *, decltype(cmp)> mismatches(cmp);
    vector<TreeNode *> lessers;
    vector<TreeNode *> greaters;

    getMismatches(root, greaters, lessers, mismatches);

    TreeNode *m1 = *mismatches.begin();
    TreeNode *m2 = *mismatches.rbegin();

    int t = m1->val;
    m1->val = m2->val;
    m2->val = t;
  }

private:
  void getMismatches(TreeNode *node, vector<TreeNode *> &greaters, vector<TreeNode *> &lessers, set<TreeNode *, decltype(cmp)> &mismatches)
  {
    if (node == nullptr)
    {
      return;
    }

    for (TreeNode *g : greaters)
    {
      if (node->val > g->val)
      {
        mismatches.insert(node);
        mismatches.insert(g);
      }
    }

    for (TreeNode *l : lessers)
    {
      if (node->val < l->val)
      {
        mismatches.insert(node);
        mismatches.insert(l);
      }
    }

    greaters.push_back(node);
    getMismatches(node->left, greaters, lessers, mismatches);
    greaters.pop_back();

    lessers.push_back(node);
    getMismatches(node->right, greaters, lessers, mismatches);
    lessers.pop_back();
  }
};

int main()
{
  Solution solution;

  TreeNode *tree1 = new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(2)), nullptr);
  solution.recoverTree(tree1);

  TreeNode *tree2 = new TreeNode(3, new TreeNode(1), new TreeNode(4, new TreeNode(2), nullptr));
  solution.recoverTree(tree2);

  TreeNode *tree3 = new TreeNode(2, new TreeNode(3), new TreeNode(1));
  solution.recoverTree(tree3);
}