// https://leetcode.com/problems/construct-quad-tree/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Node
{
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node()
  {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf)
  {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
  {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution
{
public:
  Node *construct(vector<vector<int>> &grid)
  {
    return construct(grid, 1, grid.size(), 1, grid.size());
  }

private:
  Node *construct(vector<vector<int>> &grid, int startRow, int endRow, int startCol, int endCol)
  {
    if (startRow == endRow && startCol == endCol)
    {
      return new Node(grid[startRow - 1][startCol - 1], true);
    }

    int midCol = (startCol + endCol) / 2;
    int midRow = (startRow + endRow) / 2;
    Node *topLeft = construct(grid, startRow, midRow, startCol, midCol);
    Node *topRight = construct(grid, startRow, midRow, midCol + 1, endCol);
    Node *bottomLeft = construct(grid, midRow + 1, endRow, startCol, midCol);
    Node *bottomRight = construct(grid, midRow + 1, endRow, midCol + 1, endCol);

    if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
        ((topLeft->val == topRight->val) && (topRight->val == bottomLeft->val) && (bottomLeft->val == bottomRight->val)))
    {
      return new Node(topLeft->val, true);
    }

    return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.construct(*new vector<vector<int>>{{0, 1}, {1, 0}});
  auto result2 = solution.construct(*new vector<vector<int>>{
      {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0}});
}