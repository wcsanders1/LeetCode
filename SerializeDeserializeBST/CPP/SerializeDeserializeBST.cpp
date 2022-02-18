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
      q.pop();
      if (node == NULL)
      {
        s += "null,";
      }
      else
      {
        s += to_string(node->val) + ",";
        q.push(node->left);
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
    stringstream s_stream(data);
    bool left = true;
    while (s_stream.good())
    {
      string sub;
      getline(s_stream, sub, ',');
      if (sub.size() == 0)
      {
        break;
      }

      if (q.empty())
      {
        root = new TreeNode(stoi(sub));
        q.push(root);
        continue;
      }

      if (sub == "null")
      {
        if (!left)
        {
          q.pop();
        }
        left = !left;
        continue;
      }

      int val = stoi(sub);
      TreeNode *node = q.front();
      if (left)
      {
        node->left = new TreeNode(val);
        q.push(node->left);
      }
      else
      {
        node->right = new TreeNode(val);
        q.push(node->right);
        q.pop();
      }

      left = !left;
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

int main()
{
  Codec *ser = new Codec();
  Codec *deser = new Codec();

  TreeNode *root1 = new TreeNode(2);
  root1->left = new TreeNode(1);
  root1->right = new TreeNode(3);
  string tree1 = ser->serialize(root1);
  TreeNode *ans1 = deser->deserialize(tree1);

  TreeNode *root2 = new TreeNode(1);
  root2->left = NULL;
  root2->right = new TreeNode(2);
  string tree2 = ser->serialize(root2);
  TreeNode *ans2 = deser->deserialize(tree2);
}