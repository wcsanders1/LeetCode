// https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  long long flowerGame(int n, int m)
  {
    return (n * m) / 2;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.flowerGame(3, 2);
  long long result2 = solution.flowerGame(1, 1);
}