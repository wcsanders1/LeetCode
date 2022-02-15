#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <utility>
#include <unordered_set>

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

    unordered_map<string, vector<TreeNode *>> nodesByPath;
    for (auto [path, node] : subtrees)
    {
      if (nodesByPath.count(path) == 0)
      {
        nodesByPath[path] = vector<TreeNode *>();
      }

      nodesByPath[path].push_back(node);
    }

    vector<TreeNode *> answer;
    for (auto [path, nodes] : nodesByPath)
    {
      if (nodes.size() > 1)
      {
        answer.push_back(nodes[0]);
      }
    }

    return answer;
  }

private:
  string getSubtrees(TreeNode *node, vector<pair<string, TreeNode *>> *subtrees)
  {
    if (node == nullptr)
    {
      return "NULL";
    }

    string path = "(" + to_string(node->val) + "-" +
                  "left:" + getSubtrees(node->left, subtrees) + ":left" +
                  "right:" + getSubtrees(node->right, subtrees) + ":right)";

    pair<string, TreeNode *> sub(path, node);
    subtrees->push_back(sub);

    return path;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findDuplicateSubtrees(new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(4))));

  return 0;
}