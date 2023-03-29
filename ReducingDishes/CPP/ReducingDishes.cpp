// https://leetcode.com/problems/reducing-dishes/
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
  int maxSatisfaction(vector<int> &satisfaction)
  {
    sort(satisfaction.begin(), satisfaction.end());
    int start = satisfaction.size() - 1;
    int answer = 0;
    while (start >= 0)
    {
      int temp = 0;
      int index = 1;
      for (int i = start; i < satisfaction.size(); i++)
      {
        temp += satisfaction[i] * index++;
      }
      start--;
      answer = max(answer, temp);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxSatisfaction(*new vector<int>{-1, -8, 0, 5, -9});
  int result2 = solution.maxSatisfaction(*new vector<int>{4, 3, 2});
  int result3 = solution.maxSatisfaction(*new vector<int>{-1, -4, -5});
}