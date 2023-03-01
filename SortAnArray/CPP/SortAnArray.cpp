// https://leetcode.com/problems/sort-an-array/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> sortArray(vector<int> &nums)
  {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }

private:
  void mergeSort(vector<int> &nums, int start, int end)
  {
    if (start >= end)
    {
      return;
    }

    int mid = start + (end - start) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, mid, end);
  }

  void merge(vector<int> &nums, int start, int mid, int end)
  {
    int arr1Size = mid - start + 1;
    int arr2Size = end - mid;

    vector<int> arr1(arr1Size, 0);
    vector<int> arr2(arr2Size, 0);

    for (int i = 0; i < arr1Size; i++)
    {
      arr1[i] = nums[i + start];
    }

    for (int i = 0; i < arr2Size; i++)
    {
      arr2[i] = nums[i + mid + 1];
    }

    int a1 = 0;
    int a2 = 0;
    int arrIndex = start;
    while (a1 < arr1Size && a2 < arr2Size)
    {
      if (arr1[a1] < arr2[a2])
      {
        nums[arrIndex] = arr1[a1];
        a1++;
      }
      else
      {
        nums[arrIndex] = arr2[a2];
        a2++;
      }
      arrIndex++;
    }

    while (a1 < arr1Size)
    {
      nums[arrIndex++] = arr1[a1++];
    }

    while (a2 < arr2Size)
    {
      nums[arrIndex++] = arr2[a2++];
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.sortArray(*new vector<int>{5, 2, 3, 1});
  auto result2 = solution.sortArray(*new vector<int>{5, 1, 1, 2, 0, 0});
}