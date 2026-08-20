// https://leetcode.com/problems/cinema-seat-allocation/description/?envType=daily-question&envId=2026-08-19
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
  {
    unordered_map<int, unordered_set<int>> reserved;
    for (auto &rs : reservedSeats)
    {
      if (rs[1] >= 2 && rs[1] <= 9)
      {
        reserved[rs[0]].insert(rs[1]);
      }
    }

    int groups = n * 2;
    for (const auto &[_, seats] : reserved)
    {
      bool canSeat1 = true;
      bool canSeat2 = true;
      bool canSeat3 = true;
      for (int s = 2; s <= 5; s++)
      {
        if (seats.find(s) != seats.end())
        {
          canSeat1 = false;
        }
      }
      for (int s = 4; s <= 7; s++)
      {
        if (seats.find(s) != seats.end())
        {
          canSeat2 = false;
        }
      }
      for (int s = 6; s <= 9; s++)
      {
        if (seats.find(s) != seats.end())
        {
          canSeat3 = false;
        }
      }
      if (canSeat1 || canSeat2 || canSeat3)
      {
        groups--;
      }
      else
      {
        groups -= 2;
      }
    }

    return groups;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxNumberOfFamilies(3, *new vector<vector<int>>{{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}});
  int result2 = solution.maxNumberOfFamilies(2, *new vector<vector<int>>{{2, 1}, {1, 8}, {2, 6}});
  int result3 = solution.maxNumberOfFamilies(4, *new vector<vector<int>>{{4, 3}, {1, 4}, {4, 6}, {1, 7}});
  int result4 = solution.maxNumberOfFamilies(3, *new vector<vector<int>>{{2, 3}});
  int result5 = solution.maxNumberOfFamilies(4, *new vector<vector<int>>{{2, 10}, {3, 1}, {1, 2}, {2, 2}, {3, 5}, {4, 1}, {4, 9}, {2, 7}}); // 3
}