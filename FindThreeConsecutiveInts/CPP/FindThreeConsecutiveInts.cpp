// https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/
#include <vector>

using namespace std;

class Solution
{
public:
  vector<long long> sumOfThree(long long num)
  {
    vector<int> tries{-1, 0, 1};
    long long start = num / 3;
    for (int t : tries)
    {
      long long sum = (start + t) + (start + t + 1) + (start + t + 2);
      if (sum == num)
      {
        return vector<long long>{start + t, start + t + 1, start + t + 2};
      }
    }

    return vector<long long>(0);
  }
};

int main()
{
  Solution solution;

  vector<long long> result1 = solution.sumOfThree(33);
  vector<long long> result2 = solution.sumOfThree(4);
}