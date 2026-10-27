// https://leetcode.com/problems/create-grid-with-exactly-one-path/description/?envType=daily-question&envId=2026-10-27
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<string> createGrid(int m, int n)
  {
    string first = "";
    for (int i = 0; i < n; i++)
    {
      first += ".";
    }

    vector<string> answer;
    answer.push_back(first);

    for (int i = 1; i < m; i++)
    {
      string next = "";
      for (int j = 1; j < n; j++)
      {
        next += "#";
      }
      next += ".";
      answer.push_back(next);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.createGrid(2, 3);
  auto result2 = solution.createGrid(3, 3);
  auto result3 = solution.createGrid(1, 4);
}