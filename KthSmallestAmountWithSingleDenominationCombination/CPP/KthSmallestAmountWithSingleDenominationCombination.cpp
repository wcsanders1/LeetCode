// https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/description/?envType=daily-question&envId=2026-08-21
// NOT MINE: https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/solutions/8473394/test-by-la_castille-7mst/?envType=daily-question&envId=2026-08-21
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
  using ll = long long;
  long long findKthSmallest(vector<int> &coins, int k)
  {
    sort(coins.begin(), coins.end());
    vector<int> A;

    for (auto &c : coins)
      if (none_of(A.begin(), A.end(), [&](int x)
                  { return !(c % x); }))
        A.push_back(c);

    int n = A.size();

    auto check = [&](ll mid)
    {
      ll tot = 0;
      for (int i = 1; i <= n; i++)
      {
        int q = (1 << i) - 1;

        while (q < 1 << n)
        {
          ll x = 1;
          for (int j = 0; j < n; j++)
            if ((q >> j) & 1)
              x = lcm(x, A[j]);

          tot += (mid / x) * (((i & 1) << 1) - 1);

          int c = q & -q;
          int r = q + c;
          q = (((r ^ q) >> 2) / c) | r;
        }
      }
      return tot >= k;
    };

    ll low = k, high = 1ll * A[0] * k;
    while (low < high)
    {
      ll mid = low + (high - low) / 2;

      if (check(mid))
        high = mid;
      else
        low = mid + 1;
    }

    return low;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findKthSmallest(*new vector<int>{3, 6, 9}, 3);
}