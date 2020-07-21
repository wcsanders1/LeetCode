using System;

namespace MaximumProductOfTwoElementsInArray
{
    public class Solution
    {
        public int MaxProduct(int[] nums)
        {
            if (nums == null || nums.Length < 2)
            {
                return 0;
            }

            var highest = nums[0];
            var secondHighest = 0;
            var highestIncidents = 1;

            for (int i = 1; i < nums.Length; i++)
            {
                if (nums[i] > highest)
                {
                    secondHighest = highest;
                    highest = nums[i];
                    highestIncidents = 1;
                    continue;
                }

                if (nums[i] == highest)
                {
                    highestIncidents++;
                }

                if (nums[i] > secondHighest)
                {
                    secondHighest = nums[i];
                }
            }

            if (highestIncidents > 1)
            {
                return (highest - 1) * (highest - 1);
            }

            return (highest - 1) * (secondHighest - 1);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MaxProduct(new int[] { 3, 4, 5, 2 }));
            Console.WriteLine(solution.MaxProduct(new int[] { 1, 5, 4, 5 }));

            Console.ReadKey();
        }
    }
}
