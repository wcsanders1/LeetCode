#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    sort(coins.begin(), coins.end());
    vector<long> *remainders = new vector<long>();
    remainders->push_back(0);
    
    for (long i = 1; i <= coins.back(); i++)
    {
      long remainder = i;
      int position = coins.size() - 1;
      int count = 0;
      while (remainder > 0 && position >= 0)
      {
        if (coins[position] > remainder)
        {
          position--;
        }
        else
        {
          remainder -= coins[position];
          count++;
        }
      }

      remainders->push_back(remainder == 0 ? count : -1);
    }
    
    int answer = 0;
    int r = 0;
    if (amount < coins.back())
    {
      answer = (*remainders)[amount];

      delete remainders;

      return answer;
    }

    answer = amount / coins.back();
    r = amount % coins.back();

    if ((*remainders)[r] == -1)
    {
      return -1;
    }

    answer += (*remainders)[r];

    delete remainders;

    return answer;
  }
};

int main()
{
  Solution solution;

  // int result1 = solution.coinChange(*new vector<int>{1, 2, 5}, 11);
  // int result2 = solution.coinChange(*new vector<int>{2, 5}, 11);
  // int result3 = solution.coinChange(*new vector<int>{1}, 0);
  // int result4 = solution.coinChange(*new vector<int>{1}, 1);
  int result5 = solution.coinChange(*new vector<int>{2147483647}, 2);
}