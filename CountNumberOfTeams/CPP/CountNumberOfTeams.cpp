// https://leetcode.com/problems/count-number-of-teams/
#include <vector>

using namespace std;

class Solution
{
public:
  int numTeams(vector<int> &rating)
  {
    int answer = 0;

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