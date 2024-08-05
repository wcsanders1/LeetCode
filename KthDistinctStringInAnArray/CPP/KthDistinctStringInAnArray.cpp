// https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05
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
  string kthDistinct(vector<string> &arr, int k)
  {
    unordered_map<string, int> count;
    for (string &s : arr)
    {
      count[s]++;
    }

    for (string &s : arr)
    {
      if (count[s] == 1)
      {
        k--;
      }

      if (k == 0)
      {
        return s;
      }
    }

    return "";
  }
};