// https://leetcode.com/problems/kth-missing-positive-number/description/
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
  int findKthPositive(vector<int> &arr, int k)
  {
    int last = 0;
    int answer = 0;
    for (int n : arr)
    {
      if (last < n - 1 && k > 0)
      {
        answer = last + 1;
        k--;
        while (k > 0 && answer < n - 1)
        {
          k--;
          answer++;
        }
      }
      last = n;
    }

    return k > 0 ? arr[arr.size() - 1] + k : answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findKthPositive(*new vector<int>{2, 3, 4, 7, 11}, 5);
  int result2 = solution.findKthPositive(*new vector<int>{1, 2, 3, 4}, 2);
  int result3 = solution.findKthPositive(*new vector<int>{2, 3, 4, 7, 11}, 7);
}