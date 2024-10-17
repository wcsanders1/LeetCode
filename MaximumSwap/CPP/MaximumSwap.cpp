// https://leetcode.com/problems/maximum-swap/description/?envType=daily-question&envId=2024-10-17
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int maximumSwap(int num)
  {
    string s = to_string(num);
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
      char m = s[i];
      int index = i;
      for (int j = i + 1; j < n; j++)
      {
        if (s[j] > m || (s[j] == m && index > i))
        {
          m = s[j];
          index = j;
        }
      }

      if (index != i)
      {
        char t = s[i];
        s[i] = s[index];
        s[index] = t;
        return stoi(s);
      }
    }

    return num;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maximumSwap(2736); // 7236
  int result2 = solution.maximumSwap(9973); // 9973
  int result3 = solution.maximumSwap(2796); // 9726
  int result4 = solution.maximumSwap(1993); // 9913
}