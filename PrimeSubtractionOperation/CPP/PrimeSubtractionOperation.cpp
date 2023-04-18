// https://leetcode.com/problems/prime-subtraction-operation/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution
{
public:
  bool primeSubOperation(vector<int> &nums)
  {
    auto primes = getPrimes(1000);

    for (int i = nums.size() - 2; i >= 0; i--)
    {
      if (nums[i] >= nums[i + 1])
      {
        int diff = (nums[i] - nums[i + 1]) + 1;
        int pIndex = getIndex(primes, diff, 0, primes->size() - 1);
        nums[i] -= (*primes)[pIndex];
        if (nums[i] <= 0 || nums[i] >= nums[i + 1])
        {
          return false;
        }
      }
    }

    return true;
  }

private:
  int getIndex(vector<int> *primes, int value, int start, int end)
  {
    if (start >= end)
    {
      return end;
    }

    int mid = (end + start) / 2;
    if ((*primes)[mid] == value)
    {
      return mid;
    }
    else if ((*primes)[mid] < value)
    {
      return getIndex(primes, value, mid + 1, end);
    }
    else
    {
      return getIndex(primes, value, start, mid);
    }
  }

  vector<int> *getPrimes(int max)
  {
    auto primes = new vector<int>();
    for (int i = 2; i < max; i++)
    {
      bool prime = true;
      for (int j = 2; j * j <= i; j++)
      {
        if (i % j == 0)
        {
          prime = false;
          break;
        }
      }

      if (prime)
      {
        primes->push_back(i);
      }
    }

    return primes;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.primeSubOperation(*new vector<int>{4, 9, 6, 10});
  bool result2 = solution.primeSubOperation(*new vector<int>{6, 8, 11, 12});
  bool result3 = solution.primeSubOperation(*new vector<int>{5, 8, 3});
}