// https://leetcode.com/problems/total-hamming-distance/
#include <vector>

using namespace std;

class Solution
{
public:
  int totalHammingDistance(vector<int> &nums)
  {
    int bitCount = sizeof(int) * 8;
    vector<vector<int>> counts(bitCount, vector<int>(2, 0));

    for (int n : nums)
    {
      for (int i = 0; i < bitCount; i++)
      {
        counts[i][n & 1]++;
        n = n >> 1;
      }
    }

    int answer = 0;
    for (vector<int> c : counts)
    {
      answer += c[0] * c[1];
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.totalHammingDistance(*new vector<int>{4, 14, 2});
  int result2 = solution.totalHammingDistance(*new vector<int>{4, 14, 4});
}