// https://leetcode.com/problems/word-search/description/?envType=daily-question&envId=2024-04-03
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool exist(vector<vector<char>> &board, string word)
  {
    if (!preCheck(board, word))
    {
      return false;
    }

    int rows = board.size();
    int cols = board[0].size();
    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        if (exists(board, word, visited, row, col))
        {
          return true;
        }
      }
    }

    return false;
  }

private:
  bool preCheck(vector<vector<char>> &board, string &word)
  {
    int rows = board.size();
    int cols = board[0].size();
    unordered_map<char, int> wCount;
    unordered_map<char, int> bCount;
    for (char &c : word)
    {
      wCount[c]++;
    }

    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        bCount[board[row][col]]++;
      }
    }

    for (auto &[ch, cnt] : wCount)
    {
      if (bCount[ch] < cnt)
      {
        return false;
      }
    }

    return true;
  }
  bool exists(vector<vector<char>> &board, string &word, vector<vector<bool>> &visited, int row, int col, int index = 0)
  {
    if (index >= word.size())
    {
      return true;
    }

    if (col < 0 || row < 0 || row >= board.size() || col >= board[0].size() || visited[row][col])
    {
      return false;
    }

    if (board[row][col] != word[index])
    {
      return false;
    }

    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto &d : directions)
    {
      visited[row][col] = true;
      if (exists(board, word, visited, row + d[0], col + d[1], index + 1))
      {
        return true;
      }
      visited[row][col] = false;
    }
    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.exist(*new vector<vector<char>>{{'a'}}, "a");                                                                                                                                                                                                        // true
  bool result2 = solution.exist(*new vector<vector<char>>{{'a', 'b'}, {'c', 'd'}}, "acdb");                                                                                                                                                                                    // true
  bool result3 = solution.exist(*new vector<vector<char>>{{'a', 'a'}}, "aaa");                                                                                                                                                                                                 // false
  bool result4 = solution.exist(*new vector<vector<char>>{{'a', 'b'}, {'c', 'd'}}, "cdba");                                                                                                                                                                                    // true
  bool result5 = solution.exist(*new vector<vector<char>>{{'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}}, "AAAAAAAAAAAAAAB"); // false
}