// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/?envType=daily-question&envId=2023-11-30
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  int maxCoins(vector<int> &piles)
  {
    sort(piles.begin(), piles.end());

    int answer = 0;
    int index = piles.size() - 2;
    for (int i = 0; i < piles.size() / 3; i++)
    {
      answer += piles[index];
      index -= 2;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxCoins(*new vector<int>{2, 4, 1, 2, 7, 8});
  int result2 = solution.maxCoins(*new vector<int>{2, 4, 5});
  int result3 = solution.maxCoins(*new vector<int>{9, 8, 7, 6, 5, 1, 2, 3, 4});
}