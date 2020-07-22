using System;

namespace ProductOfArrayExceptSelf
{
    public class Solution
    {
        public int[] ProductExceptSelf(int[] nums)
        {
            var result = new int[nums.Length];

            if (nums == null || nums.Length == 0)
            {
                return result;
            }

            var beginResults = new int[nums.Length];
            beginResults[0] = nums[0];

            for (int i = 1; i < nums.Length; i++)
            {
                beginResults[i] = nums[i] * beginResults[i - 1];
            }

            result[nums.Length - 1] = beginResults[nums.Length - 2];

            var endResults = new int[nums.Length];
            endResults[^1] = nums[^1];

            for (int i = nums.Length - 2; i >= 0; i--)
            {
                if (i == 0)
                {
                    result[0] = endResults[1];
                }
                else
                {
                    result[i] = beginResults[i - 1] * endResults[i + 1];
                }

                endResults[i] = nums[i] * endResults[i + 1];
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var resultOne = solution.ProductExceptSelf(new int[] { 1, 2, 3, 4 });

            Console.ReadKey();
        }
    }
}
