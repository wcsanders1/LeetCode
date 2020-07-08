using System;

namespace SearchInRotatedSortedArrayII
{
    public class Solution
    {
        public bool Search(int[] nums, int target)
        {
            if (nums == null || nums.Length == 0)
            {
                return false;
            }

            var low = 0;
            var hi = nums.Length - 1;

            while (low <= hi)
            {
                var mid = (low + hi) >> 1;
                if (nums[mid] == target)
                {
                    return true;
                }

                if (nums[low] == nums[mid] && nums[hi] == nums[mid])
                {
                    low++;
                    hi--;
                }
                else if (nums[low] <= nums[mid])
                {
                    if (nums[low] <= target && nums[mid] > target)
                    {
                        hi = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if (nums[mid] < target && nums[hi] >= target)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        hi = mid - 1;
                    }
                }
            }

            return false;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var arrOne = new int[] { 2, 5, 6, 0, 0, 1, 2 };
            var arrTwo = new int[] { 1, 2, 5, 6, 8, 9, 0 };
            var arrThree = new int[] { 1, 3 };
            var arrFour = new int[] { 1 };
            var arrFive = new int[] { 5, 1, 3 };
            var arrSix = new int[] { 2, 2, 2, 0, 2, 2 };

            Console.WriteLine(solution.Search(arrOne, 0));
            Console.WriteLine(solution.Search(arrTwo, 3));
            Console.WriteLine(solution.Search(arrThree, 3));
            Console.WriteLine(solution.Search(arrFour, 1));
            Console.WriteLine(solution.Search(arrFive, 1));
            Console.WriteLine(solution.Search(arrSix, 0));

            Console.ReadKey();
        }
    }
}
