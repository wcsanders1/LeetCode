#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution
{
public:
  int monkeyMove(int n)
  {
    long moves = power(2, n);

    return int((moves - 2 + 1000000007) % 1000000007);
  }

private:
  long power(int num, int p)
  {
    if (p == 0)
    {
      return 1;
    }

    if (p == 1)
    {
      return num;
    }

    long result = power(num, p / 2);
    result = (result * result) % 1000000007;
    if (p % 2 > 0)
    {
      result = (result * num) % 1000000007;
    }

    return result;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.monkeyMove(3);
  int result2 = solution.monkeyMove(4);
  int result3 = solution.monkeyMove(500000003);
}