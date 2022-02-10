// Not from my own personal mind

#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class Node
{
public:
  string value;
  map<string, Node *> children;
  bool canDelete = false;
  Node(string value = "/") : value(value) {}
};

class Solution
{
public:
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
  {
    Node tree;
    for (vector<string> &path : paths)
    {
      buildTree(&tree, path);
    }
    deduplicate(&tree);
    for (auto &[name, child] : tree.children)
    {
      getPath(child);
    }
    return answer;
  }

private:
  void buildTree(Node *node, vector<string> &path)
  {
    for (string &s : path)
    {
      if (!node->children.count(s))
      {
        node->children[s] = new Node(s);
      }
      node = node->children[s];
    }
  }
  unordered_map<string, Node *> seen;
  string deduplicate(Node *node)
  {
    string fullname;
    for (auto &[name, child] : node->children)
    {
      fullname += deduplicate(child);
    }

    if (fullname.size())
    {
      if (seen.count(fullname))
      {
        seen[fullname]->canDelete = node->canDelete = true;
      }
      else
      {
        seen[fullname] = node;
      }
    }

    return "(" + node->value + fullname + ")";
  }

  vector<vector<string>> answer;
  vector<string> path;
  void getPath(Node *node)
  {
    if (node->canDelete)
    {
      return;
    }
    path.push_back(node->value);
    answer.push_back(path);
    for (auto &[name, child] : node->children)
    {
      getPath(child);
    }
    path.pop_back();
  }
};

int main()
{
  Solution solution;
  vector<vector<string>> result1 = solution.deleteDuplicateFolder(
      *new vector<vector<string>>{
          *new vector<string>{"a"},
          *new vector<string>{"c"},
          *new vector<string>{"a", "b"},
          *new vector<string>{"c", "b"},
          *new vector<string>{"a", "b", "x"},
          *new vector<string>{"a", "b", "x", "y"},
          *new vector<string>{"w"},
          *new vector<string>{"w", "y"}});

  vector<vector<string>> result2 = solution.deleteDuplicateFolder(
      *new vector<vector<string>>{
          *new vector<string>{"a"},
          *new vector<string>{"b"},
          *new vector<string>{"a", "x"},
          *new vector<string>{"a", "z"},
          *new vector<string>{"b", "x"},
          *new vector<string>{"b", "z"},
          *new vector<string>{"a", "x", "y"},
          *new vector<string>{"b", "x", "y"}});

  vector<vector<string>> result3 = solution.deleteDuplicateFolder(
      *new vector<vector<string>>{
          *new vector<string>{"a"},
          *new vector<string>{"c"},
          *new vector<string>{"d"},
          *new vector<string>{"a", "b"},
          *new vector<string>{"c", "b"},
          *new vector<string>{"d", "a"}});

  vector<vector<string>> result4 = solution.deleteDuplicateFolder(
      *new vector<vector<string>>{
          *new vector<string>{"a"},
          *new vector<string>{"c"},
          *new vector<string>{"a", "b"},
          *new vector<string>{"c", "d"}});
}