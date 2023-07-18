// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
// NOT MINE: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/solutions/398196/c-o-n-dp-using-hashmap/
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
  int longestSubsequence(vector<int> &arr, int difference)
  {
    int n = arr.size();
    unordered_map<int, int> m;
    int answer = 1;

    for (int &num : arr)
    {
      m[num] = 1 + m[num - difference];
      answer = max(answer, m[num]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.longestSubsequence(*new vector<int>{1, 2, 3, 4}, 1);
  int result2 = solution.longestSubsequence(*new vector<int>{1, 3, 5, 7}, 1);
  int result3 = solution.longestSubsequence(*new vector<int>{1, 5, 7, 8, 5, 3, 4, 2, 1}, -2);
  int result4 = solution.longestSubsequence(*new vector<int>{4, 12, 10, 0, -2, 7, -8, 9, -9, -12, -12, 8, 8}, 0);
}