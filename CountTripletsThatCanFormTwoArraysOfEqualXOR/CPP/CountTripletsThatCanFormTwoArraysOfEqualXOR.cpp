// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/?envType=daily-question&envId=2024-05-30
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
  int countTriplets(vector<int> &arr)
  {
    int answer = 0;
    int n = arr.size();
    if (n < 2)
    {
      return answer;
    }

    for (int i = 0; i < n - 1; i++)
    {
      int a = arr[i];
      for (int j = i + 1; j < n; j++)
      {
        a ^= arr[j];
        int b = arr[j];
        for (int k = j; k < n; k++)
        {
          b ^= arr[k];
          if (a == b)
          {
            answer++;
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

  int result1 = solution.countTriplets(*new vector<int>{2, 3, 1, 6, 7}); // 4
  int result2 = solution.countTriplets(*new vector<int>{1, 1, 1, 1, 1}); // 10
  int result3 = solution.countTriplets(*new vector<int>{1, 3, 5, 7, 9}); // 3
}