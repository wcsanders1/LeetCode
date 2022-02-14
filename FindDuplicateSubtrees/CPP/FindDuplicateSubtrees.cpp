#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <utility>

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
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
  {
    vector<pair<string, TreeNode *>> subtrees;
    getSubtrees(root, &subtrees);

    vector<TreeNode *> answer;

    return answer;
  }

private:
  string getSubtrees(TreeNode *node, vector<pair<string, TreeNode *>> *subtrees)
  {
    if (node == nullptr)
    {
      return "";
    }

    string path = "(" + to_string(node->val) + ")" + getSubtrees(node->left, subtrees) + getSubtrees(node->right, subtrees);

    pair<string, TreeNode *> sub(path, node);
    subtrees->push_back(sub);

    return path;
  }
};