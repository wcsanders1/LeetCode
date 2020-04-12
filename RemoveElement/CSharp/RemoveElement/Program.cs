using System;

namespace RemoveElement
{
    public class Solution
    {
        public int RemoveElement(int[] nums, int val)
        {
            if (nums == null || nums.Length == 0)
            {
                return 0;
            }

            var beginning = 0;
            var end = 0;
            while (end < nums.Length)
            {
                while (end < nums.Length && nums[end] == val)
                {
                    end++;
                }

                if (end >= nums.Length || nums[end] == val)
                {
                    return beginning;
                }

                nums[beginning++] = nums[end++];
            }

            return beginning;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var array1 = new int[] { 3, 2, 2, 3 };
            var array2 = new int[] { 0, 1, 2, 2, 3, 0, 4, 2 };
            var array3 = new int[] { 3 };
            var array4 = new int[] { 3, 4 };
            var array5 = new int[] { 1, 2, 3, 4 };

            var result1 = solution.RemoveElement(array1, 3);
            var result2 = solution.RemoveElement(array2, 2);
            var result3 = solution.RemoveElement(array3, 3);
            var result4 = solution.RemoveElement(array4, 3);
            var result5 = solution.RemoveElement(array5, 1);

            Console.ReadKey();
        }
    }
}
