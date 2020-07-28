using System;

namespace LongestIncreasingSubsequence
{
    public class Solution
    {
        public int LengthOfLIS(int[] nums)
        {
            if (nums == null || nums.Length == 0)
            {
                return 0;
            }

            var dp = new int[nums.Length];

            var result = 0;

            for (var i = nums.Length - 2; i >= 0; i--)
            {
                var num = nums[i];
                var greatest = 0;
                for (var j = i + 1; j < nums.Length; j++)
                {
                    if (num < nums[j] && greatest <= dp[j])
                    {
                        greatest = dp[j] + 1;
                    }
                }

                dp[i] = greatest;

                if (result < greatest)
                {
                    result = greatest;
                }
            }

            return result + 1;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.LengthOfLIS(new int[] { 10, 9, 2, 5, 3, 7, 101, 18 }));

            Console.ReadKey();
        }
    }
}
