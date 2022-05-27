// https://leetcode.com/problems/candy/
#include <vector>

using namespace std;

class Solution
{
public:
  int candy(vector<int> &ratings)
  {
    int length = ratings.size();

    if (length == 0)
    {
      return 0;
    }

    if (length == 1)
    {
      return 1;
    }

    int total = 0;
    int start = 0;
    int end = 0;

    while (end < length)
    {
      while (end < length - 1 && ratings[end + 1] < ratings[end])
      {
        end++;
      }

      if (start < end)
      {
        total += getIncrementalSum(end - start);
        start = end;
      }

      while (end < length - 1 && ratings[end + 1] > ratings[end])
      {
        end++;
      }

      if (start < end)
      {
        total += getIncrementalSum(end - start);
        start = end;
      }

      while (end < length - 1 && ratings[end + 1] == ratings[end])
      {
        total++;
        start++;
        end++;
      }

      end++;
    }

    return total;
  }

private:
  int getIncrementalSum(int num)
  {
    int sum = 0;
    for (int i = 1; i <= num + 1; i++)
    {
      sum += i;
    }

    return sum;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.candy(*new vector<int>{1, 0, 2}); // 5
  int result2 = solution.candy(*new vector<int>{1, 2, 2}); // 4
}