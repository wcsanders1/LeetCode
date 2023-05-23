// https://leetcode.com/problems/kth-largest-element-in-a-stream/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class KthLargest
{
public:
  KthLargest(int k, vector<int> &nums) : k(k), nums(nums)
  {
    sort(this->nums.begin(), this->nums.end());
  }

  int add(int val)
  {
    if (nums.size() == 0)
    {
      nums.push_back(val);
    }
    else if (val > nums[nums.size() - 1])
    {
      nums.push_back(val);
    }
    else
    {
      int index = getIndex(val, 0, nums.size() - 1);
      nums.insert(nums.begin() + index, val);
    }
    return nums[nums.size() - k];
  }

private:
  int k;
  vector<int> &nums;

  int getIndex(int val, int start, int end)
  {
    if (start >= end)
    {
      return start;
    }

    int mid = (end + start) / 2;
    if (nums[mid] == val)
    {
      return mid;
    }

    if (val < nums[mid])
    {
      return getIndex(val, start, mid);
    }

    return getIndex(val, mid + 1, end);
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
  KthLargest *solution = new KthLargest(3, *new vector<int>{4, 5, 8, 2});

  int result1 = solution->add(3);
  int result2 = solution->add(5);
  int result3 = solution->add(10);
  int result4 = solution->add(9);
  int result5 = solution->add(4);
}