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

    vector<vector<string>> *result = new vector<vector<string>>();
    prune(tree, result);

    return *result;
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

  void prune(Node *node, vector<vector<string>> *result, vector<string> *currentPath = nullptr)
  {
    if (!node->Children.size())
    {
      return;
    }

    for (Node *child : node->Children)
    {
      if (child->canDelete)
      {
        continue;
      }
      else
      {
        if (currentPath == NULL)
        {
          currentPath = new vector<string>();
        }
        currentPath->push_back(child->Value);
        result->push_back(*currentPath);
        vector<string> *newPath = new vector<string>();
        for (string s : *currentPath)
        {
          newPath->push_back(s);
        }
        prune(child, result, newPath);
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