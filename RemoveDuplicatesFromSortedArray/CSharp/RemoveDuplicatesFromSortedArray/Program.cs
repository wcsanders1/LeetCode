using System;

namespace RemoveDuplicatesFromSortedArray
{
    public class Solution
    {
        public int RemoveDuplicates(int[] nums)
        {
            var first = 0;
            var second = 1;

            if (nums == null || nums.Length == 0)
            {
                return 0;
            }

            while (second < nums.Length)
            {
                var firstNum = nums[first];
                var secondNum = nums[second];

                if (second - first == 1 && firstNum != secondNum)
                {
                    first++;
                    second++;
                    continue;
                }

                if (firstNum == secondNum)
                {
                    while (second < nums.Length && nums[second] == firstNum)
                    {
                        second++;
                    }

                    if (second >= nums.Length)
                    {
                        return ++first;
                    }
                }
                nums[++first] = nums[second++];
            }

            return ++first;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var array1 = new int[] { 1, 1, 2 };
            var array2 = new int[] { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
            var array3 = new int[0];
            var array4 = new int[] { 0, 1, 2, 3, 4 };
            var array5 = new int[] { 6 };
            var array6 = new int[] { 1, 1 };

            var result1 = solution.RemoveDuplicates(array1);
            var result2 = solution.RemoveDuplicates(array2);
            var result3 = solution.RemoveDuplicates(array3);
            var result4 = solution.RemoveDuplicates(array4);
            var result5 = solution.RemoveDuplicates(array5);
            var result6 = solution.RemoveDuplicates(array6);

            Console.ReadKey();
        }
    }
}
