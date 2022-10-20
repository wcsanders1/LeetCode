// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/
// NOT MINE: https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/discuss/1527753/Binary-Search-and-Two-Pointers
// simple solution: https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/discuss/1524343/C%2B%2B-or-Answer-on-Binary-Search
#include <vector>

using namespace std;

class Solution
{
public:
  long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
  {
    vector<int>::iterator lp = lower_bound(begin(nums1), end(nums1), 0);
    vector<int>::iterator rp = lower_bound(begin(nums2), end(nums2), 0);
    vector<int> neg1(begin(nums1), lp);
    vector<int> neg2(begin(nums2), rp);
    vector<int> pos1(lp, end(nums1));
    vector<int> pos2(rp, end(nums2));
    vector<int> pos1_r(rbegin(pos1), rend(pos1));
    vector<int> pos2_r(rbegin(pos2), rend(pos2));
    vector<int> neg1_r(rbegin(neg1), rend(neg1));
    vector<int> neg2_r(rbegin(neg2), rend(neg2));

    long long l = -10000000000;
    long long r = 10000000000;

    while (l < r)
    {
      long long m = (l + r - 1) / 2;
      long long cnt = 0;

      if (m >= 0)
      {
        cnt = count(neg1_r, neg2_r, m) + count(pos1, pos2, m) + neg1.size() * pos2.size() + neg2.size() * pos1.size();
      }
      else
      {
        cnt = count(pos2_r, neg1, m) + count(pos1_r, neg2, m);
      }

      if (cnt < k)
      {
        l = m + 1;
      }
      else
      {
        r = m;
      }
    }

    return l;
  }

private:
  long long count(vector<int> &n1, vector<int> &n2, long long m)
  {
    long long cnt = 0;
    for (int p1 = 0, p2 = n2.size() - 1; p1 < n1.size(); ++p1)
    {
      while (p2 >= 0 && (long long)n1[p1] * n2[p2] > m)
      {
        --p2;
      }
      cnt += p2 + 1;
    }
    return cnt;
  }
};

int main()
{
  Solution solution;

  // long long result1 = solution.kthSmallestProduct(*new vector<int>{-2, -1, 0, 1, 2}, *new vector<int>{-3, -1, 2, 4, 5}, 3);
  long long result2 = solution.kthSmallestProduct(*new vector<int>{3}, *new vector<int>{-3}, 1);
}