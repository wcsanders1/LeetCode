using System;

namespace FindMinimumInRotatedSortedArray
{
    public class Solution
    {
        public int FindMin(int[] nums)
        {
            if (nums.Length == 1)
            {
                return nums[0];
            }

            var start = 0;
            var end = nums.Length - 1;
            var middle = (end + start) / 2;


            while (start < end)
            {
                if (nums[start] < nums[end])
                {
                    return nums[start];
                }

                if (end - start == 1)
                {
                    return Math.Min(nums[start], nums[end]);
                }

                if (nums[middle] < nums[middle - 1])
                {
                    return nums[middle];
                }

                if (nums[middle] > nums[middle + 1])
                {
                    return nums[middle + 1];
                }

                if (nums[middle] > nums[end])
                {
                    start = middle;
                }
                else
                {
                    end = middle;
                }

                middle = (end + start) / 2;
            }

            return nums[middle];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.FindMin(new int[] { 3, 4, 5, 1, 2 }));
            Console.WriteLine(solution.FindMin(new int[] { 4, 5, 6, 7, 0, 1, 2 }));
            Console.WriteLine(solution.FindMin(new int[] { 1, 2 }));
            Console.WriteLine(solution.FindMin(new int[] { 1, 2, 3 }));
            Console.WriteLine(solution.FindMin(new int[] { 2, 3, 4, 5, 1 }));

            Console.ReadKey();
        }
    }
}
