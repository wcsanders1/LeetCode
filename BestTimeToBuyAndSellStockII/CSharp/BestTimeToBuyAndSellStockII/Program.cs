using System;

namespace BestTimeToBuyAndSellStockII
{
    public class Solution
    {
        public int MaxProfit(int[] prices)
        {
            if (prices == null || prices.Length < 2)
            {
                return 0;
            }

            var result = 0;
            var lastProfit = 0;

            for (int i = 1; i < prices.Length; i++)
            {
                var currentPrice = prices[i];
                var previousPrice = prices[i - 1];

                if (currentPrice < previousPrice)
                {
                    result += lastProfit;
                    lastProfit = 0;
                }
                else if (currentPrice > previousPrice)
                {
                    lastProfit += currentPrice - previousPrice;
                }
            }

            return result += lastProfit;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MaxProfit(new int[] { 7, 1, 5, 3, 6, 4 }));
            Console.WriteLine(solution.MaxProfit(new int[] { 1, 2, 3, 4, 5 }));
            Console.WriteLine(solution.MaxProfit(new int[] { 7, 6, 4, 3, 1 }));

            Console.ReadKey();
        }
    }
}
