// https://leetcode.com/problems/snakes-and-ladders/description/
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution
{
public:
  int snakesAndLadders(vector<vector<int>> &board)
  {
    vector<int> longBoard;
    bool right = true;
    for (int row = board.size() - 1; row >= 0; row--)
    {
      if (right)
      {
        for (int col = 0; col <= board[row].size() - 1; col++)
        {
          longBoard.push_back(board[row][col]);
        }
      }
      else
      {
        for (int col = board[row].size() - 1; col >= 0; col--)
        {
          longBoard.push_back(board[row][col]);
        }
      }
      right = !right;
    }

    unordered_map<int, int> cache;
    set<int> visited;

    return getLeastSteps(0, cache, longBoard, visited);
  }

private:
  int getLeastSteps(int square, unordered_map<int, int> &cache, vector<int> &longBoard, set<int> &visited)
  {
    if (square >= longBoard.size() - 1)
    {
      return 0;
    }

    if (square >= longBoard.size() - 7)
    {
      return 1;
    }

    if (cache.count(square) > 0)
    {
      return cache[square];
    }

    int least = (longBoard.size() - square + 1) / 6;
    for (int i = square + 1; i <= square + 6; i++)
    {
      int next = longBoard[i] == -1 ? i : longBoard[i] - 1;
      if (visited.count(next) > 0)
      {
        continue;
      }
      visited.insert(next);
      least = min(least, getLeastSteps(next, cache, longBoard, visited) + 1);
    }

    cache[square] = least;

    return least;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.snakesAndLadders(*new vector<vector<int>>{
      {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, 35, -1, -1, 13, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, 15, -1, -1, -1, -1}});
  int result2 = solution.snakesAndLadders(*new vector<vector<int>>{
      {-1, -1},
      {-1, 3}});
}