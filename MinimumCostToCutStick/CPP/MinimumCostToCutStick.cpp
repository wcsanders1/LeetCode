// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
  int minCost(int n, vector<int> &cuts)
  {
    sort(cuts.begin(), cuts.end());
    unordered_map<string, int> mem;
    return minCost(cuts, mem, 0, n);
  }

private:
  int minCost(vector<int> &cuts, unordered_map<string, int> &mem, int start, int end, int count = 0)
  {
    if (count > cuts.size())
    {
      return 0;
    }

    string key = to_string(start) + "&" + to_string(end);
    if (mem.count(key) != 0)
    {
      return mem[key];
    }

    int length = end - start;
    int minimum = INT32_MAX;

    for (int cut : cuts)
    {
      if (cut > start && cut < end)
      {
        minimum = min(minimum, (minCost(cuts, mem, start, cut, count + 1) + minCost(cuts, mem, cut, end, count + 1) + length));
      }
    }

    minimum = minimum == INT32_MAX ? 0 : minimum;
    mem[key] = minimum;
    return minimum;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minCost(7, *new vector<int>{1, 3, 4, 5});
  int result2 = solution.minCost(9, *new vector<int>{5, 6, 1, 4, 2});
}