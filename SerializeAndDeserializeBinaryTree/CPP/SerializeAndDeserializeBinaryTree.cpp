// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
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
  string serialize(TreeNode *root)
  {
    stringstream *ss = new stringstream();
    serialize(root, ss);
    return ss->str();
  }

  TreeNode *deserialize(string data)
  {
    queue<string> q;
    stringstream ss(data);
    while (ss.good())
    {
      string substr;
      getline(ss, substr, ',');
      q.push(substr);
    }

    return deserialize(q);
  }

private:
  void serialize(TreeNode *node, stringstream *ss)
  {
    if (node == nullptr)
    {
      *ss << "null,";
      return;
    }

    *ss << (to_string(node->val) + ",");
    serialize(node->left, ss);
    serialize(node->right, ss);
  }

  TreeNode *deserialize(queue<string> &q)
  {
    if (q.empty() || q.front() == "null" || q.front() == "")
    {
      q.pop();
      return nullptr;
    }

    int val = stoi(q.front());
    q.pop();
    auto node = new TreeNode(val);
    node->left = deserialize(q);
    node->right = deserialize(q);
    return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
  Codec ser, deser;
  auto node1 = new TreeNode(1);
  auto node2 = new TreeNode(2);
  auto node3 = new TreeNode(3);
  auto node4 = new TreeNode(4);
  auto node5 = new TreeNode(5);

  node1->left = node2;
  node1->right = node3;
  node3->left = node4;
  node3->right = node5;

  string sresult1 = ser.serialize(node1);
  auto nresult1 = deser.deserialize(sresult1);
}