// https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  bool lemonadeChange(vector<int> &bills)
  {
    int fives = 0;
    int tens = 0;
    for (int &bill : bills)
    {
      switch (bill)
      {
      case 5:
        fives++;
        break;
      case 10:
        if (fives == 0)
        {
          return false;
        }
        fives--;
        tens++;
        break;
      case 20:
        if (tens > 0)
        {
          if (fives == 0)
          {
            return false;
          }
          tens--;
          fives--;
        }
        else if (fives >= 3)
        {
          fives -= 3;
        }
        else
        {
          return false;
        }
        break;
      }
    }

    return true;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.lemonadeChange(*new vector<int>{5, 5, 5, 10, 20});
  bool result2 = solution.lemonadeChange(*new vector<int>{5, 5, 10, 10, 20});
}