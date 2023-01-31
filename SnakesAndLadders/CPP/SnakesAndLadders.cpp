// https://leetcode.com/problems/snakes-and-ladders/description/
// NOT MINE: https://leetcode.com/problems/snakes-and-ladders/solutions/173403/change-to-1d-array-then-bfs/?orderBy=most_votes
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int snakesAndLadders(vector<vector<int>> &board)
  {
    vector<int> longBoard;
    int boardSize = board.size() * board.size();
    bool right = true;
    vector<bool> visited(boardSize + 1, false);

    longBoard.push_back(0);
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

    queue<int> q;
    q.push(1);
    visited[1] = true;
    int count = 1;

    while (!q.empty())
    {
      int moves = q.size();
      for (int move = 0; move < moves; move++)
      {
        int square = q.front();
        q.pop();
        if (square == boardSize)
        {
          return count;
        }

        for (int i = 1; i <= 6; i++)
        {
          int next = square + i;
          if (longBoard[next] != -1)
          {
            next = longBoard[next];
          }

          if (next == boardSize)
          {
            return count;
          }

          if (visited[next])
          {
            continue;
          }
          visited[next] = true;
          q.push(next);
        }
      }
      count++;
    }

    return -1;
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
      {-1, 15, -1, -1, -1, -1}}); // 4
  int result2 = solution.snakesAndLadders(*new vector<vector<int>>{
      {-1, -1},
      {-1, 3}}); // 1
  int result3 = solution.snakesAndLadders(*new vector<vector<int>>{
      {-1, 4, -1},
      {6, 2, 6},
      {-1, 3, -1}}); // 2
}