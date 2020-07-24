using System;

namespace MaxDotProductOfTwoSubsequences
{
    public class Solution
    {
        public int MaxDotProduct(int[] nums1, int[] nums2)
        {
            var dp = new int[nums1.Length][];

            for (int i = 0; i < nums1.Length; i++)
            {
                dp[i] = new int[nums2.Length];

                for (int j = 0; j < nums2.Length; j++)
                {
                    dp[i][j] = nums1[i] * nums2[j];

                    if(i > 0 && j > 0)
                    {
                        dp[i][j] += Math.Max(dp[i - 1][j - 1], 0);
                    }

                    if (i > 0)
                    {
                        dp[i][j] = Math.Max(dp[i][j], dp[i - 1][j]);
                    }

                    if (j > 0)
                    {
                        dp[i][j] = Math.Max(dp[i][j], dp[i][j - 1]);
                    }
                }
            }

            return dp[nums1.Length - 1][nums2.Length - 1];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MaxDotProduct(new int[] { 2, 1, -2, 5 }, new int[] { 3, 0, -6 }));

            Console.ReadKey();
        }
    }
}
