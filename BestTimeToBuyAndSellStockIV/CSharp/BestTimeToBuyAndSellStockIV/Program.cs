using System;

namespace BestTimeToBuyAndSellStockIV
{
    public class Solution
    {
        public int MaxProfit(int k, int[] prices)
        {
            if (prices == null || prices.Length == 0 || k == 0)
            {
                return 0;
            }

            if (k >= prices.Length / 2)
            {
                var profit = 0;
                for (int i = 1; i < prices.Length; i++)
                {
                    if (prices[i] > prices[i - 1])
                    {
                        profit += prices[i] - prices[i - 1];
                    }
                }

                return profit;
            }

            var dp = new int[k + 1][];
            for (int i = 0; i < k + 1; i++)
            {
                dp[i] = new int[prices.Length];
            }

            var min = new int[k];
            Array.Fill(min, prices[0]);

            for (int i = 1; i < prices.Length; i++)
            {
                for (int j = 1; j <= k; j++)
                {
                    min[j - 1] = Math.Min(min[j - 1], prices[i] - dp[j - 1][i - 1]);
                    dp[j][i] = Math.Max(dp[j][i - 1], prices[i] - min[j - 1]);
                }
            }

            return dp[k][prices.Length - 1];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MaxProfit(2, new int[] { 2, 4, 1 }));
            Console.WriteLine(solution.MaxProfit(2, new int[] { 3, 2, 6, 5, 0, 3 }));
            Console.WriteLine(solution.MaxProfit(2, new int[] { 2, 1, 4 }));

            Console.ReadKey();
        }
    }
}
