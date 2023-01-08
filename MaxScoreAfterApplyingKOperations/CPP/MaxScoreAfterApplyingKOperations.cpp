#include <vector>
#include <cmath>
#include <queue>

using namespace std;

class Solution
{
public:
  long long maxKelements(vector<int> &nums, int k)
  {
    priority_queue<int> q;
    for (int n : nums)
    {
      q.push(n);
    }

    long long answer = 0;
    while (k-- > 0)
    {
      int num = q.top();
      q.pop();
      answer += num;
      num = ceil((double)num / 3);
      q.push(num);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.maxKelements(*new vector<int>{10, 10, 10, 10, 10}, 5);
  long long result2 = solution.maxKelements(*new vector<int>{1, 10, 3, 3, 3}, 3);
  long long result3 = solution.maxKelements(*new vector<int>{756902131, 995414896, 95906472, 149914376, 387433380, 848985151}, 6);
}