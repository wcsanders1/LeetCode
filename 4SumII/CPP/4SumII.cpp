// https://leetcode.com/problems/4sum-ii/
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
  {
    int size = nums1.size();
    vector<int> sums = vector<int>(size * size, 0);
    unordered_map<int, int> nums;
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        int index = (i * size) + j;
        sums[index] = nums1[i] + nums2[j];

        int sum = nums3[i] + nums4[j];
        if (nums.count(sum) == 0)
        {
          nums[sum] = 0;
        }
        nums[sum]++;
      }
    }

    int answer = 0;
    for (int s : sums)
    {
      int z = s * -1;
      if (nums.count(z) != 0)
      {
        answer += nums[z];
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.fourSumCount(*new vector<int>{1, 2}, *new vector<int>{-2, -1}, *new vector<int>{-1, 2}, *new vector<int>{0, 2});
  int result2 = solution.fourSumCount(*new vector<int>{0}, *new vector<int>{0}, *new vector<int>{0}, *new vector<int>{0});
}