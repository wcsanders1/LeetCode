// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/?envType=daily-question&envId=2024-04-29
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums, int k)
  {
    int exor = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
      exor = exor ^ nums[i];
    }

    int answer = 0;
    for (int i = 0; i < 32; i++)
    {
      int a = exor & 1;
      exor >>= 1;
      int b = k & 1;
      k >>= 1;
      answer += a == b ? 0 : 1;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minOperations(*new vector<int>{2, 1, 3, 4}, 1);                  // 2
  int result2 = solution.minOperations(*new vector<int>{2, 0, 2, 0}, 0);                  // 0
  int result3 = solution.minOperations(*new vector<int>{2}, 2);                           // 0
  int result4 = solution.minOperations(*new vector<int>{3, 13, 9, 8, 5, 18, 11, 10}, 13); // 2
}