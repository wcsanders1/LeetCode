// https://leetcode.com/problems/wiggle-sort-ii/
// NOT MINE: https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void wiggleSort(vector<int> &nums)
  {
    int n = nums.size();

    // Find a median.
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

// Index-rewiring.
#define A(i) nums[(1 + 2 * (i)) % (n | 1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
    {
      if (A(j) > mid)
        swap(A(i++), A(j++));
      else if (A(j) < mid)
        swap(A(j), A(k--));
      else
        j++;
    }
  }
};

int main()
{
  Solution solution;

  solution.wiggleSort(*new vector<int>{1, 5, 1, 1, 6, 4});
  solution.wiggleSort(*new vector<int>{1, 3, 2, 2, 3, 1});
}