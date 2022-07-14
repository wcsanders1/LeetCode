// https://leetcode.com/problems/detect-cycles-in-2d-grid/
#include <vector>

using namespace std;

class Solution
{
public:
  bool containsCycle(vector<vector<char>> &grid)
  {
    if (grid.size() < 2 || grid[0].size() < 2)
    {
      return false;
    }

    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

    for (int x = 0; x < grid.size(); x++)
    {
      for (int y = 0; y < grid[x].size(); y++)
      {
        if (visited[x][y])
        {
          continue;
        }

        visited[x][y] = true;
        if (cycleExists(grid, visited, *new vector<int>{x, y}, *new vector<int>{-1, -1}))
        {
          return true;
        }
      }
    }

    return false;
  }

private:
  vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool cycleExists(vector<vector<char>> &grid, vector<vector<bool>> &visited, vector<int> &currentNode, vector<int> &priorNode)
  {
    for (vector<int> direction : directions)
    {
      int currentX = currentNode[0];
      int currentY = currentNode[1];
      int newX = currentX + direction[0];
      int newY = currentY + direction[1];

      if (newX == priorNode[0] && newY == priorNode[1])
      {
        continue;
      }

      if (newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size())
      {
        if (grid[newX][newY] == grid[currentX][currentY])
        {
          if (visited[newX][newY])
          {
            return true;
          }

          visited[newX][newY] = true;
          if (cycleExists(grid, visited, *new vector<int>{newX, newY}, currentNode))
          {
            return true;
          }
        }
      }
    }

    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.containsCycle(*new vector<vector<char>>{
      {'a', 'a', 'a', 'a'},
      {'a', 'b', 'b', 'a'},
      {'a', 'b', 'b', 'a'},
      {'a', 'a', 'a', 'a'}});

  bool result2 = solution.containsCycle(*new vector<vector<char>>{
      {'c', 'c', 'c', 'a'},
      {'c', 'd', 'c', 'c'},
      {'c', 'c', 'e', 'c'},
      {'f', 'c', 'c', 'c'}});

  bool result3 = solution.containsCycle(*new vector<vector<char>>{
      {'a', 'b', 'b'},
      {'b', 'z', 'b'},
      {'b', 'b', 'a'}});
}