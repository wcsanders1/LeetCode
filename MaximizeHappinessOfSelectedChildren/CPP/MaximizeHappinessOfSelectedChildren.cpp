// https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2024-05-09
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  long long maximumHappinessSum(vector<int> &happiness, int k)
  {
    sort(happiness.begin(), happiness.end(), greater<>());
    long long answer = 0;
    for (int i = 0; i < k; i++)
    {
      answer += max(0, happiness[i] - i);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.maximumHappinessSum(*new vector<int>{1, 2, 3}, 2);
  long long result2 = solution.maximumHappinessSum(*new vector<int>{1, 1, 1, 1}, 2);
  long long result3 = solution.maximumHappinessSum(*new vector<int>{2, 3, 4, 5}, 1);
}