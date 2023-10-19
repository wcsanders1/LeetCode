// https://leetcode.com/problems/validate-binary-tree-nodes/?envType=daily-question&envId=2023-10-17
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
  {
    vector<int> isChild(n, -1);
    for (int i = 0; i < n; i++)
    {
      if (isChild[i] != 1)
      {
        isChild[i] = 0;
      }

      if (leftChild[i] != -1)
      {
        isChild[leftChild[i]] = 1;
      }

      if (rightChild[i] != -1)
      {
        isChild[rightChild[i]] = 1;
      }
    }

    int root = -1;
    for (int i = 0; i < n; i++)
    {
      if (isChild[i] == 0)
      {
        if (root != -1)
        {
          return false;
        }

        root = i;
      }
    }

    vector<bool> visited(n, false);
    if (!isValid(root, leftChild, rightChild, visited))
    {
      return false;
    }

    for (int i = 0; i < n; i++)
    {
      if ((leftChild[i] != -1 || rightChild[i] != -1) && !visited[i])
      {
        return false;
      }
    }

    return true;
  }

private:
  bool isValid(int node, vector<int> &leftChild, vector<int> &rightChild, vector<bool> &visited)
  {
    if (node == -1)
    {
      return true;
    }

    if (visited[node])
    {
      return false;
    }

    visited[node] = true;

    return isValid(leftChild[node], leftChild, rightChild, visited) && isValid(rightChild[node], leftChild, rightChild, visited);
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.validateBinaryTreeNodes(4, *new vector<int>{1, -1, 3, -1}, *new vector<int>{2, -1, -1, -1});                // true
  bool result2 = solution.validateBinaryTreeNodes(4, *new vector<int>{1, -1, 3, -1}, *new vector<int>{2, 3, -1, -1});                 // false
  bool result3 = solution.validateBinaryTreeNodes(2, *new vector<int>{1, 0}, *new vector<int>{-1, -1});                               // false
  bool result4 = solution.validateBinaryTreeNodes(6, *new vector<int>{1, -1, -1, 4, -1, -1}, *new vector<int>{2, -1, -1, 5, -1, -1}); // false
  bool result5 = solution.validateBinaryTreeNodes(4, *new vector<int>{3, -1, 1, -1}, *new vector<int>{-1, -1, 0, -1});                // true
}