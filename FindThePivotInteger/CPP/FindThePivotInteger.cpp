// https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int pivotInteger(int n)
  {
    int start = 1;
    int end = n;
    int sumStart = 1;
    int sumEnd = n;

    while (start < end)
    {
      if (sumStart < sumEnd)
      {
        sumStart += ++start;
      }
      else if (sumStart > sumEnd)
      {
        sumEnd += --end;
      }
      else
      {
        sumStart += ++start;
        sumEnd += --end;
      }
    }

    return (start == end && sumStart == sumEnd) ? start : -1;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.pivotInteger(8);
  int result2 = solution.pivotInteger(1);
  int result3 = solution.pivotInteger(4);
  int result4 = solution.pivotInteger(1000);
}