// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
  int findBestValue(vector<int> &arr, int target)
  {
    sort(arr.begin(), arr.end(), greater<>());

    int total = 0;
    for (int num : arr)
    {
      total += num;
    }

    int difference = abs(total - target);
    int answer = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
      int t = arr[i];
      if (i == arr.size() - 1)
      {
        while (t-- > 0)
        {
          total -= arr.size();
          int d = abs(total - target);
          if (d <= difference)
          {
            answer = t;
            difference = d;
          }
        }
      }
      else
      {
        while (t-- > arr[i + 1])
        {
          total -= i + 1;
          int d = abs(total - target);
          if (d <= difference)
          {
            answer = t;
            difference = d;
          }
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findBestValue(*new vector<int>{4, 9, 3}, 10);
  int result2 = solution.findBestValue(*new vector<int>{2, 3, 5}, 10);
  int result3 = solution.findBestValue(*new vector<int>{60864, 25176, 27249, 21296, 20204}, 56803);
  int result4 = solution.findBestValue(*new vector<int>{2, 2}, 3);
}