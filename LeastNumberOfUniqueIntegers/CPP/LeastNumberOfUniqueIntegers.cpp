#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

class Solution
{
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k)
  {
    map<int, int> numsByTimes;
    for (int num : arr)
    {
      if (numsByTimes.count(num) == 0)
      {
        numsByTimes[num] = 0;
      }

      numsByTimes[num]++;
    }

    int uniqueNums = numsByTimes.size();

    map<int, int> timesByNums;
    for (auto const &[num, times] : numsByTimes)
    {
      if (timesByNums.count(times) == 0)
      {
        timesByNums[times] = 0;
      }

      timesByNums[times]++;
    }

    for (auto const &[times, num] : timesByNums)
    {
      int n = num;
      while (n-- > 0)
      {
        if (k < times)
        {
          return uniqueNums;
        }

        uniqueNums--;
        k -= times;
      }
    }

    return uniqueNums;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findLeastNumOfUniqueInts(*new vector<int>{5, 5, 4}, 1);
  int result2 = solution.findLeastNumOfUniqueInts(*new vector<int>{4, 3, 1, 1, 3, 3, 2}, 3);
}