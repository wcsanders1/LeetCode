// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// NOT MINE: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84607/Clean-16ms-C%2B%2B-O(N)-Space-O(KlogN)-Time-Solution-using-Priority-queue
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    vector<vector<int>> result;
    if (nums1.empty() || nums2.empty() || k <= 0)
    {
      return result;
    }

    auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b)
    {
      return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
    min_heap.emplace(0, 0);

    while (k-- > 0 && min_heap.size())
    {
      auto idx_pair = min_heap.top();
      min_heap.pop();
      result.emplace_back(vector<int>{nums1[idx_pair.first], nums2[idx_pair.second]});

      if (idx_pair.first + 1 < nums1.size())
      {
        min_heap.emplace(idx_pair.first + 1, idx_pair.second);
      }

      if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
      {
        min_heap.emplace(idx_pair.first, idx_pair.second + 1);
      }
    }

    return result;
  }
};

int main()
{
  Solution solution;

  vector<vector<int>> result1 = solution.kSmallestPairs(*new vector<int>{1, 7, 11}, *new vector<int>{2, 4, 6}, 3);
  vector<vector<int>> result2 = solution.kSmallestPairs(*new vector<int>{1, 1, 2}, *new vector<int>{1, 2, 3}, 2);
  vector<vector<int>> result3 = solution.kSmallestPairs(*new vector<int>{1, 2}, *new vector<int>{3}, 3);
  vector<vector<int>> result4 = solution.kSmallestPairs(*new vector<int>{0, 0, 0, 0, 0}, *new vector<int>{-3, 22, 35, 56, 76}, 22);
}