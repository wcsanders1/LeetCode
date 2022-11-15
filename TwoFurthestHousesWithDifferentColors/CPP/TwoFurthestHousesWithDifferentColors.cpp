// https://leetcode.com/problems/two-furthest-houses-with-different-colors/
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int maxDistance(vector<int> &colors)
  {
    int answer = 0;
    for (int i = 0; i < colors.size(); i++)
    {
      for (int j = colors.size() - 1; j >= 0; j--)
      {
        if (colors[j] != colors[i])
        {
          answer = max(answer, j - i);
        }
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxDistance(*new vector<int>{1, 1, 1, 6, 1, 1, 1});
  int result2 = solution.maxDistance(*new vector<int>{1, 8, 3, 8, 3});
  int result3 = solution.maxDistance(*new vector<int>{0, 1});
  int result4 = solution.maxDistance(*new vector<int>{4, 4, 4, 11, 4, 4, 11, 4, 4, 4, 4, 4});
}