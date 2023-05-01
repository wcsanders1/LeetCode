// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  double average(vector<int> &salary)
  {
    int high = 0;
    int low = INT32_MAX;
    double total = 0;

    for (int &s : salary)
    {
      high = max(high, s);
      low = min(low, s);
      total += s;
    }

    total -= (low + high);

    return total / (double)(salary.size() - 2);
  }
};

int main()
{
  Solution solution;

  double result1 = solution.average(*new vector<int>{4000, 3000, 1000, 2000});
  double result2 = solution.average(*new vector<int>{1000, 2000, 3000});
}