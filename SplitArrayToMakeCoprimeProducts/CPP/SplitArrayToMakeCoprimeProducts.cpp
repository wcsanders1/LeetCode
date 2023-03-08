// https://leetcode.com/problems/split-the-array-to-make-coprime-products/
// NOT MINE: https://leetcode.com/problems/split-the-array-to-make-coprime-products/solutions/3258070/prime-intervals-vs-count-primes/?orderBy=most_votes
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int findValidSplit(vector<int> &nums)
  {
    unordered_map<int, int> factorIndexes;
    vector<int> lines(10001, 0);
    for (int i = 0; i < nums.size(); i++)
    {
      vector<int> factors = getPrimeFactors(nums[i]);
      for (int f : factors)
      {
        if (factorIndexes.count(f) == 0)
        {
          factorIndexes[f] = i;
        }
        ++lines[factorIndexes[f]];
        --lines[i];
      }
    }

    partial_sum(lines.begin(), lines.end(), lines.begin());
    int answer = find(lines.begin(), lines.end(), 0) - lines.begin();

    return answer < nums.size() - 1 ? answer : -1;
  }

private:
  vector<int> getPrimeFactors(int n)
  {
    vector<int> factors;
    for (int i = 2; n > 1 && i < 1000; i += 1 + (i % 2))
    {
      if (n % i == 0)
      {
        factors.push_back(i);
        while (n % i == 0)
        {
          n /= i;
        }
      }
    }

    if (n > 1)
    {
      factors.push_back(n);
    }

    return factors;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findValidSplit(*new vector<int>{4, 7, 8, 15, 3, 5});
  int result2 = solution.findValidSplit(*new vector<int>{4, 7, 15, 8, 3, 5});
  int result3 = solution.findValidSplit(*new vector<int>{557663, 280817, 472963});
}