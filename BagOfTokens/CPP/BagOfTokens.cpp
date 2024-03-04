// https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int bagOfTokensScore(vector<int> &tokens, int power)
  {
    sort(tokens.begin(), tokens.end());
    int low = 0;
    int high = tokens.size() - 1;
    int answer = 0;
    int curScore = 0;

    while (low <= high)
    {
      if (tokens[low] <= power)
      {
        answer = max(answer, ++curScore);
        power -= tokens[low++];
      }
      else if (curScore > 0)
      {
        curScore--;
        power += tokens[high--];
      }
      else
      {
        return answer;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.bagOfTokensScore(*new vector<int>{100}, 50);
  int result2 = solution.bagOfTokensScore(*new vector<int>{200, 100}, 150);
  int result3 = solution.bagOfTokensScore(*new vector<int>{100, 200, 300, 400}, 200);
}