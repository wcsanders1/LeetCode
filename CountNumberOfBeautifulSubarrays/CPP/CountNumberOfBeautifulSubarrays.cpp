// https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/
// NOT MINE: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/solutions/3286256/count-subarrays-with-zero-xor/?orderBy=most_votes
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  long long beautifulSubarrays(vector<int> &nums)
  {
    long long answer = 0;
    unordered_map<int, int> m{{0, 1}};
    int val = 0;
    for (int n : nums)
    {
      val ^= n;
      answer += m[val]++;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.beautifulSubarrays(*new vector<int>{4, 3, 1, 2, 4});
}