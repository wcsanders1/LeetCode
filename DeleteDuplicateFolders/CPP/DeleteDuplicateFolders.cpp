#include <vector>
#include <string>
#include <map>

using namespace std;

class Node
{
public:
  string Value;
  vector<Node *> Children;
  bool canDelete;
};

class Solution
{
public:
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
  {
    Node *tree = new Node();
    tree->Value = "/";

    for (vector<string> path : paths)
    {
      Node *currentNode = tree;
      for (string s : path)
      {
        Node *matchngNode = NULL;
        for (Node *n : currentNode->Children)
        {
          if (n->Value == s)
          {
            matchngNode = n;
            break;
          }
        }

        if (matchngNode == NULL)
        {
          matchngNode = new Node();
          matchngNode->Value = s;
          currentNode->Children.push_back(matchngNode);
        }

        currentNode = matchngNode;
      }
    }

    map<string, vector<Node *> *> childrenToParents;
    mapChildrenToParents(tree, childrenToParents);

    vector<vector<string>> result;
    return result;
  }

private:
  void mapChildrenToParents(Node *node, map<string, vector<Node *> *> &childrenToParents)
  {
    for (Node *child : node->Children)
    {
      if (!child->Children.size())
      {
        if (childrenToParents.count(child->Value))
        {
          child->canDelete = true;
          for (Node *parent : *(childrenToParents[child->Value]))
          {
            parent->canDelete = true;
          }
          (*childrenToParents[child->Value]).push_back(child);
        }
        else
        {
          childrenToParents.insert({child->Value, new vector<Node *>{node}});
        }
      }
      else
      {
        mapChildrenToParents(child, childrenToParents);
        bool canDelete = true;
        for (Node *subChild : child->Children)
        {
          if (!subChild->canDelete)
          {
            canDelete = false;
            break;
          }
        }
        child->canDelete = canDelete;
      }
    }
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
}