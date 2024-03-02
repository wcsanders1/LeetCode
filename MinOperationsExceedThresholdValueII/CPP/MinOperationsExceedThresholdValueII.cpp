// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums, int k)
  {
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for (int &n : nums)
    {
      q.push(n);
    }

    int answer = 0;
    while (q.size() >= 2 && q.top() < k)
    {
      answer++;
      long long x = q.top();
      q.pop();
      long long y = q.top();
      q.pop();
      q.push((x * 2) + y);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minOperations(*new vector<int>{2, 11, 10, 1, 3}, 10);
  int result2 = solution.minOperations(*new vector<int>{1, 1, 2, 4, 9}, 20);
}