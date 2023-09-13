// https://leetcode.com/problems/candy/
// not mine
#include <vector>

using namespace std;

class Solution
{
public:
  int candy(vector<int> &ratings)
  {
    int length = ratings.size();

    vector<int> fromLeft(length, 1);
    vector<int> fromRight(length, 1);

    for (int i = 1; i < length; i++)
    {
      if (ratings[i] > ratings[i - 1])
      {
        fromLeft[i] = fromLeft[i - 1] + 1;
      }
    }

    for (int i = length - 2; i >= 0; i--)
    {
      if (ratings[i] > ratings[i + 1])
      {
        fromRight[i] = fromRight[i + 1] + 1;
      }
    }

    int total = 0;
    for (int i = 0; i < length; i++)
    {
      total += max(fromLeft[i], fromRight[i]);
    }

    return total;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.candy(*new vector<int>{1, 0, 2});                     // 5
  int result2 = solution.candy(*new vector<int>{1, 2, 2});                     // 4
  int result3 = solution.candy(*new vector<int>{1, 3, 2, 2, 1});               // 7
  int result4 = solution.candy(*new vector<int>{12, 4, 3, 11, 34, 34, 1, 67}); // 16
}