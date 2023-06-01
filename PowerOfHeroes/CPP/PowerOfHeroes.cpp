// https://leetcode.com/problems/power-of-heroes/
// NOT MINE: https://leetcode.com/problems/power-of-heroes/solutions/3520202/c-java-python3-explanation-and-stepping-through-the-code/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  int sumOfPower(vector<int> &nums)
  {
    long long answer = 0;
    long long pre = 0;
    long long mod = 1e9 + 7;
    sort(nums.begin(), nums.end());

    for (long long x : nums)
    {
      answer = (answer + (x * x % mod) * x % mod + (x * x % mod) * pre % mod) % mod;
      pre = (pre * 2 + x) % mod;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.sumOfPower(*new vector<int>{2, 1, 4});
  int result2 = solution.sumOfPower(*new vector<int>{1, 1, 1});
}