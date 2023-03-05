#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int passThePillow(int n, int time)
  {
    int i = 1;
    bool forward = true;
    while (time-- > 0)
    {
      if (forward)
      {
        if (i >= n)
        {
          forward = false;
          i--;
        }
        else
        {
          i++;
        }
      }
      else
      {
        if (i <= 1)
        {
          forward = true;
          i++;
        }
        else
        {
          i--;
        }
      }
    }
    return i;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.passThePillow(4, 5);
  int result2 = solution.passThePillow(3, 2);
  int result3 = solution.passThePillow(3, 6);
  int result4 = solution.passThePillow(100, 100);
}