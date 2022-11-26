// https://leetcode.com/problems/maximum-performance-of-a-team/
// NOT MINE: https://leetcode.com/problems/maximum-performance-of-a-team/discuss/539687/JavaC%2B%2BPython-Priority-Queue
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
  {
    vector<pair<int, int>> ess(n);
    for (int i = 0; i < n; i++)
    {
      ess[i] = {efficiency[i], speed[i]};
    }

    sort(rbegin(ess), rend(ess));
    long long total_speed = 0;
    long long answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;

    for (auto &[e, s] : ess)
    {
      q.push(s);
      total_speed += s;
      if (q.size() > k)
      {
        total_speed -= q.top();
        q.pop();
      }
      answer = max(answer, total_speed * e);
    }

    return answer % (int)(1000000007);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxPerformance(6,
                                        *new vector<int>{2, 10, 3, 1, 5, 8},
                                        *new vector<int>{5, 4, 3, 9, 7, 2}, 2); // 60
  int result2 = solution.maxPerformance(6,
                                        *new vector<int>{2, 10, 3, 1, 5, 8},
                                        *new vector<int>{5, 4, 3, 9, 7, 2}, 3); // 68
  int result3 = solution.maxPerformance(6,
                                        *new vector<int>{2, 10, 3, 1, 5, 8},
                                        *new vector<int>{5, 4, 3, 9, 7, 2}, 4); // 72
  int result4 = solution.maxPerformance(3,
                                        *new vector<int>{2, 8, 2},
                                        *new vector<int>{2, 7, 1}, 2); // 56
  int result5 = solution.maxPerformance(5,
                                        *new vector<int>{10, 10, 7, 9, 8},
                                        *new vector<int>{9, 8, 3, 6, 9}, 1); // 90
  int result6 = solution.maxPerformance(8,
                                        *new vector<int>{9, 9, 4, 6, 9, 7, 9, 8},
                                        *new vector<int>{1, 9, 1, 9, 8, 1, 10, 1}, 4); // 264
  int result7 = solution.maxPerformance(2,
                                        *new vector<int>{1, 1000},
                                        *new vector<int>{2, 1}, 1); // 1000
}