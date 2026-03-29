// https://leetcode.com/problems/ones-and-zeroes/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int findMaxForm(vector<string> &strs, int m, int n)
  {
    unordered_map<string, pair<int, int>> counts;
    for (string &s : strs)
    {
      if (counts.find(s) == counts.end())
      {
        int z = 0;
        int o = 0;
        for (char &c : s)
        {
          if (c == '0')
          {
            z++;
          }

          if (c == '1')
          {
            o++;
          }
        }
        counts[s] = {z, o};
      }
    }

    vector<vector<vector<int>>> mem(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    return getCount(strs, counts, mem, m, n, 0);
  }

private:
  int getCount(vector<string> &strs, unordered_map<string, pair<int, int>> &counts, vector<vector<vector<int>>> &mem, int zeros, int ones, int index)
  {
    if ((zeros == 0 && ones == 0) || index >= strs.size())
    {
      return 0;
    }

    if (mem[index][zeros][ones] != -1)
    {
      return mem[index][zeros][ones];
    }

    string &s = strs[index];
    int z = counts[s].first;
    int o = counts[s].second;

    int res;
    if (z > zeros || o > ones)
    {
      res = getCount(strs, counts, mem, zeros, ones, index + 1);
    }
    else
    {
      int a = 1 + getCount(strs, counts, mem, zeros - z, ones - o, index + 1);
      int b = getCount(strs, counts, mem, zeros, ones, index + 1);
      res = max(a, b);
    }

    mem[index][zeros][ones] = res;
    return res;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findMaxForm(*new vector<string>{"10", "0001", "111001", "1", "0"}, 5, 3);                                                                                                                                                                                                                                                    // 4
  int result2 = solution.findMaxForm(*new vector<string>{"10", "0", "1"}, 1, 1);                                                                                                                                                                                                                                                                      // 2
  int result3 = solution.findMaxForm(*new vector<string>{"00011", "00001", "00001", "0011", "111"}, 8, 5);                                                                                                                                                                                                                                            // 3
  int result4 = solution.findMaxForm(*new vector<string>{"011", "1", "11", "0", "010", "1", "10", "1", "1", "0", "0", "0", "01111", "011", "11", "00", "11", "10", "1", "0", "0", "0", "0", "101", "001110", "1", "0", "1", "0", "0", "10", "00100", "0", "10", "1", "1", "1", "011", "11", "11", "10", "10", "0000", "01", "1", "10", "0"}, 44, 39); // 45
}