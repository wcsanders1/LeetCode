// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
#include <vector>

using namespace std;

class Solution
{
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold)
  {
    int start = 0;
    int end = 0;
    long long total = 0;
    int answer = 0;

    for (end; end < k; end++)
    {
      total += arr[end];
    }

    double average = (double)total / (double)k;
    if (average >= threshold)
    {
      answer++;
    }

    while (end < arr.size())
    {
      total -= arr[start++];
      total += arr[end++];

      average = total / k;
      if (average >= threshold)
      {
        answer++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numOfSubarrays(*new vector<int>{2, 2, 2, 2, 5, 5, 5, 8}, 3, 4);
  int result2 = solution.numOfSubarrays(*new vector<int>{11, 13, 17, 23, 29, 31, 7, 5, 2, 3}, 3, 5);
}