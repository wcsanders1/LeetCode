// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/

using namespace std;

class Solution
{
public:
  int countOdds(int low, int high)
  {
    int t = (high - low) / 2;
    return ((low % 2 == 1) || (high % 2 == 1)) ? t + 1 : t;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.countOdds(3, 7);
  int result2 = solution.countOdds(8, 10);
  int result3 = solution.countOdds(0, 3);
}