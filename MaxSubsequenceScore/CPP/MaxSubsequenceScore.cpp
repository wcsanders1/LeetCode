// https://leetcode.com/problems/maximum-subsequence-score/
// NOT MINE: https://leetcode.com/problems/maximum-subsequence-score/solutions/3082106/java-c-python-priority-queue/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
  {
    int n = nums1.size();
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++)
    {
      pairs[i] = {nums2[i], nums1[i]};
    }

    sort(pairs.rbegin(), pairs.rend());

    priority_queue<int, vector<int>, greater<int>> q;

    long long answer = 0;
    long long curSum = 0;

    for (auto pair : pairs)
    {
      q.push(pair.second);
      curSum += pair.second;

      if (q.size() > k)
      {
        curSum -= q.top();
        q.pop();
      }

      if (q.size() == k)
      {
        answer = max(answer, curSum * pair.first);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.maxScore(*new vector<int>{1, 3, 3, 2}, *new vector<int>{2, 1, 3, 4}, 3);        // 12
  auto result2 = solution.maxScore(*new vector<int>{4, 2, 3, 1, 1}, *new vector<int>{7, 5, 10, 9, 6}, 1); // 30
  auto result3 = solution.maxScore(*new vector<int>{1, 4}, *new vector<int>{3, 1}, 2);                    // 5
  auto result4 = solution.maxScore(*new vector<int>{2, 1, 14, 12}, *new vector<int>{11, 7, 13, 6}, 3);    // 168
}