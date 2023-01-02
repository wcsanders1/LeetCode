// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  string removeDigit(string number, char digit)
  {
    int index = -1;
    for (int i = number.size() - 1; i >= 0; i--)
    {
      if (number[i] == digit)
      {
        if (i < number.size() - 1 && number[i + 1] > digit)
        {
          index = i;
        }
        else if (index == -1)
        {
          index = i;
        }
      }
    }

    number.erase(index, 1);

    return number;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.removeDigit("123", '3');
  string result2 = solution.removeDigit("1231", '1');
  string result3 = solution.removeDigit("551", '5');
  string result4 = solution.removeDigit("133235", '3');
}