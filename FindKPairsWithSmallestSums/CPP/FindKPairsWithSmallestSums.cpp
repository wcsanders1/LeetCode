// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
#include <vector>
#include <queue>

using namespace std;

class Compare
{
public:
  bool operator()(vector<int> pair1, vector<int> pair2)
  {
    return pair1[0] + pair1[1] > pair2[0] + pair2[1];
  }
};

class Solution
{
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    for (int i = 0; i < nums1.size(); i++)
    {
      for (int j = 0; j < nums2.size(); j++)
      {
        pq.push(vector<int>{nums1[i], nums2[j]});
      }
    }

    vector<vector<int>> answer;
    while (k-- > 0 && !pq.empty())
    {
      answer.push_back(pq.top());
      pq.pop();
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  vector<vector<int>> result1 = solution.kSmallestPairs(*new vector<int>{1, 7, 11}, *new vector<int>{2, 4, 6}, 3);
  vector<vector<int>> result2 = solution.kSmallestPairs(*new vector<int>{1, 1, 2}, *new vector<int>{1, 2, 3}, 2);
  vector<vector<int>> result3 = solution.kSmallestPairs(*new vector<int>{1, 2}, *new vector<int>{3}, 3);
}