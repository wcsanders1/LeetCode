// https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> maxScoreIndices(vector<int> &nums)
  {
    int totalOnes = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 1)
      {
        totalOnes++;
      }
    }

    int onesRight = totalOnes;
    int zerosLeft = 0;
    vector<int> scores(nums.size() + 1, 0);
    scores[0] = totalOnes;
    scores[scores.size() - 1] = nums.size() - totalOnes;
    int highest = max(scores[0], scores[scores.size() - 1]);

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
      {
        zerosLeft++;
      }
      else
      {
        onesRight--;
      }

      int score = zerosLeft + onesRight;
      scores[i + 1] = score;
      highest = max(highest, score);
    }

    vector<int> indexes;
    for (int i = 0; i < scores.size(); i++)
    {
      if (scores[i] == highest)
      {
        indexes.push_back(i);
      }
    }

    return indexes;
  }
};

int main()
{
  Solution solution;

  vector<int> result1 = solution.maxScoreIndices(*new vector<int>{0, 0, 1, 0});
  vector<int> result2 = solution.maxScoreIndices(*new vector<int>{0, 0, 0});
  vector<int> result3 = solution.maxScoreIndices(*new vector<int>{1, 1});
}