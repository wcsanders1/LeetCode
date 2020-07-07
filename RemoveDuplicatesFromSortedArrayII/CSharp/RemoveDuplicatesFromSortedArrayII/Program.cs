using System;

namespace RemoveDuplicatesFromSortedArrayII
{
    public class Solution
    {
        public int RemoveDuplicates(int[] nums)
        {
            if (nums == null || nums.Length < 3)
            {
                return nums.Length;
            }

            var writePointer = 0;
            var prevNum = nums[0];
            var prevNumInstances = 1;

            for (int seekPointer = 1; seekPointer < nums.Length; seekPointer++)
            {
                if (prevNum == nums[seekPointer])
                {
                    prevNumInstances++;
                }
                else
                {
                    prevNum = nums[seekPointer];
                    prevNumInstances = 1;
                }

                if (prevNumInstances <= 2)
                {
                    writePointer++;
                    nums[writePointer] = nums[seekPointer];
                }
            }

            return writePointer + 1;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var numsOne = new int[] { 1, 1, 1, 2, 2, 3 };
            var numsTwo = new int[] { 0, 0, 1, 1, 1, 1, 2, 3, 3 };

            var resultOne = solution.RemoveDuplicates(numsOne);
            var resultTwo = solution.RemoveDuplicates(numsTwo);

            Console.ReadKey();
        }
    }
}
