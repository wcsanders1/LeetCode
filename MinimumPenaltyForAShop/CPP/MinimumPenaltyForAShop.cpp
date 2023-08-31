// https://leetcode.com/problems/minimum-penalty-for-a-shop/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int bestClosingTime(string customers)
  {
    int answer = 0;
    int total = 0;
    int highest = 0;

    for (int i = 0; i < customers.size(); i++)
    {
      total += customers[i] == 'Y' ? 1 : -1;
      if (total > highest)
      {
        answer = i + 1;
        highest = total;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.bestClosingTime("YYNY");
  int result2 = solution.bestClosingTime("NNNN");
  int result3 = solution.bestClosingTime("YYYY");
  int result4 = solution.bestClosingTime("YN");
}