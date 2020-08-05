using System;

namespace BestTimeToBuyAndSellStockIII
{
    public class Solution
    {
        public int MaxProfit(int[] prices)
        {
            if (prices == null || prices.Length == 0)
            {
                return 0;
            }

            var dp = new int[3][];
            for (int i = 0; i < 3; i++)
            {
                dp[i] = new int[prices.Length];
            }

            var min = new int[2];
            Array.Fill(min, prices[0]);

            for (int i = 1; i < prices.Length; i++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    min[k - 1] = Math.Min(min[k - 1], prices[i] - dp[k - 1][i - 1]);
                    dp[k][i] = Math.Max(dp[k][i - 1], prices[i] - min[k - 1]);
                }
            }

            return dp[2][prices.Length - 1];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MaxProfit(new int[] { 3, 3, 5, 0, 0, 3, 1, 4 }));
            Console.WriteLine(solution.MaxProfit(new int[] { 1, 2, 3, 4, 5 }));
            Console.WriteLine(solution.MaxProfit(new int[] { 7, 6, 4, 3, 1 }));
            Console.WriteLine(solution.MaxProfit(new int[] { 2, 1, 2, 0, 1 }));

            Console.ReadKey();
        }
    }
}
