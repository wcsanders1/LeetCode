// https://leetcode.com/problems/count-number-of-teams/
#include <vector>

using namespace std;

class Solution
{
public:
  int numTeams(vector<int> &rating)
  {
    vector<int> less = vector<int>(rating.size(), 0);
    vector<int> more = vector<int>(rating.size(), 0);

    for (int i = rating.size() - 1; i >= 0; i--)
    {
      int l = 0;
      int m = 0;
      int num = rating[i];
      for (int j = rating.size() - 1; j > i; j--)
      {
        l += rating[j] < num ? 1 : 0;
        m += rating[j] > num ? 1 : 0;
      }

      less[i] = l;
      more[i] = m;
    }

    int answer = 0;
    for (int i = 0; i < rating.size(); i++)
    {
      int num = rating[i];
      int l = less[i] <= 1 ? INT32_MAX : i + 1;
      int m = more[i] <= 1 ? INT32_MAX : i + 1;

      while (l < less.size())
      {
        if (rating[l] < num)
        {
          answer += less[l];
        }

        l++;
      }

      while (m < more.size())
      {
        if (rating[m] > num)
        {
          answer += more[m];
        }

        m++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.numTeams(*new vector<int>{2, 5, 3, 4, 1});
  int result2 = solution.numTeams(*new vector<int>{2, 1, 3});
  int result3 = solution.numTeams(*new vector<int>{1, 2, 3, 4});
}