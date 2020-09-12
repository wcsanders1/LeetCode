using System;
using System.Linq;

namespace MissingNumber
{
    public class Solution
    {
        public int MissingNumber(int[] nums)
        {
            var expectedTotal = 0;
            for (int i = 1; i <= nums.Length; i++)
            {
                expectedTotal += i;
            }

            return expectedTotal - nums.Sum();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MissingNumber(new int[] { 3, 0, 1 }));
            Console.WriteLine(solution.MissingNumber(new int[] { 9, 6, 4, 2, 3, 5, 7, 0, 1 }));

            Console.ReadKey();
        }
    }
}
