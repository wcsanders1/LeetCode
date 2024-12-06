// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/?envType=daily-question&envId=2024-12-06
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int maxCount(vector<int> &banned, int n, int maxSum)
  {
    unordered_set<int> s;
    for (int n : banned)
    {
      s.insert(n);
    }

    int answer = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
      if (s.count(i) == 0)
      {
        sum += i;
        if (sum <= maxSum)
        {
          answer++;
        }
        else
        {
          return answer;
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxCount(*new vector<int>{1, 6, 5}, 5, 6);
  int result2 = solution.maxCount(*new vector<int>{1, 2, 3, 4, 5, 6, 7}, 8, 1);
  int result3 = solution.maxCount(*new vector<int>{11}, 7, 50);
}