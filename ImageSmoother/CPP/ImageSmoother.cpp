// https://leetcode.com/problems/image-smoother/?envType=daily-question&envId=2023-12-19
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &img)
  {
    int rows = img.size();
    int cols = img[0].size();
    vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    vector<vector<int>> answer(rows, vector<int>(cols, 0));
    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < cols; col++)
      {
        int count = 1;
        int total = img[row][col];
        for (auto &d : directions)
        {

          int r = row + d[0];
          int c = col + d[1];
          if (r >= 0 && r < rows && c >= 0 && c < cols)
          {
            count++;
            total += img[r][c];
          }
        }
        answer[row][col] = total / count;
      }
    }

    return answer;
  }
};