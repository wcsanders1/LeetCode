#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    string s = "";
    if (root == NULL)
    {
      return s;
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *node = q.front();
      s += to_string(node->val) + ",";
      q.pop();
      if (node->left != NULL)
      {
        q.push(node->left);
      }
      if (node->right != NULL)
      {
        q.push(node->right);
      }
    }

    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    if (data.size() == 0)
    {
      return NULL;
    }

    TreeNode *root;
    queue<TreeNode *> q;
    q.push(root);
    stringstream s_stream(data);
    while (s_stream.good())
    {
      string sub;
      getline(s_stream, sub, ',');
      int val = stoi(sub);
      TreeNode *node = q.front();
      q.pop();
      node->val = val;
      node->left = new TreeNode();
    }

    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;