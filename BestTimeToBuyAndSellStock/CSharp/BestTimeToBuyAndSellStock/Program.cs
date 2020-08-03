using System;

namespace BestTimeToBuyAndSellStock
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
            var currentLowest = prices[0];

            for (int i = 1; i < prices.Length; i++)
            {
                var price = prices[i];
                var profit = price - currentLowest;

                if (price < currentLowest)
                {
                    currentLowest = price;
                }
                else if (profit > result)
                {
                    result = profit;
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

            Console.WriteLine(solution.MaxProfit(new int[] { 7, 1, 5, 3, 6, 4 }));
            Console.WriteLine(solution.MaxProfit(new int[] { 7, 6, 4, 3, 1 }));

            Console.ReadKey();
        }
    }
}
