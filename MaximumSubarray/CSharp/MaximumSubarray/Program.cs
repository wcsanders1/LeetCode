using System;

namespace MaximumSubarray
{
    public class Solution
    {
        public int MaxSubArray(int[] nums)
        {
            var result = int.MinValue;
            var tempTotal = 0;
            var i = 0;
            while (i < nums.Length)
            {
                if (nums[i] < 0)
                {
                    var negTotal = 0;
                    var highestNegative = int.MinValue;
                    while (i < nums.Length && nums[i] < 0)
                    {
                        if (nums[i] > highestNegative)
                        {
                            highestNegative = nums[i];
                        }

                        negTotal += nums[i++];
                    }

                    if (i == nums.Length && result == int.MinValue)
                    {
                        return highestNegative;
                    }
                    else if (tempTotal + negTotal < 0)
                    {
                        if (tempTotal > result)
                        {
                            result = tempTotal;
                        }
                        tempTotal = 0;
                    }
                    else
                    {
                        tempTotal += negTotal;
                    }
                }
                else
                {
                    while (i < nums.Length && nums[i] >= 0)
                    {
                        tempTotal += nums[i++];
                    }
                    if (tempTotal > result)
                    {
                        result = tempTotal;
                    }
                }
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MaxSubArray(new int[] { -2, 1, -3, 4, -1, 2, 1, -5, 4 })); // 6
            Console.WriteLine(solution.MaxSubArray(new int[] { -2, -1, -3, 4, -1, -2, -1, -5, -4 })); //4
            Console.WriteLine(solution.MaxSubArray(new int[] { -2, -1, -3, -4, -1, -2, -1, -5, -4 })); //-1
            Console.WriteLine(solution.MaxSubArray(new int[] { -2, -1, -3, -4, -1, -2, -1, 0, -4 })); //0

            Console.ReadKey();
        }
    }
}
