#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> countBits(int n)
  {
    vector<int> answer(n + 1, 0);
    int goBack = 1;
    int lastPowerOfTwo = 0;
    for (int i = 1; i <= n; i++)
    {
      if (isPowerOfTwo(i))
      {
        lastPowerOfTwo = i;
        answer[i] = 1;
        goBack = i / 2;
      }
      else if (i >= lastPowerOfTwo + goBack)
      {
        answer[i] = answer[i - goBack] + 1;
      }
      else
      {
        answer[i] = answer[i - goBack];
      }
    }
    return answer;
  }

private:
  bool isPowerOfTwo(int n)
  {
    return (n & (n - 1)) == 0;
  }
};

int main()
{
  Solution solution;

  vector<int> result1 = solution.countBits(16);
}