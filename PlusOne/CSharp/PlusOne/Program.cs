using System;

namespace PlusOne
{
    public class Solution
    {
        public int[] PlusOne(int[] digits)
        {
            for (var i = digits.Length - 1; i >= 0; i--)
            {
                var newSum = digits[i] + 1;
                if (newSum < 10)
                {
                    digits[i] = newSum;
                    return digits;
                }

                digits[i] = 0;
            }

            var newDigits = new int[digits.Length + 1];
            newDigits[0] = 1;

            return newDigits;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.PlusOne(new int[] { 1, 2, 3 });
            var result2 = solution.PlusOne(new int[] { 4, 3, 2, 1 });
            var result3 = solution.PlusOne(new int[] { 0 });
            var result4 = solution.PlusOne(new int[] { 9, 9, 9 });
            var result5 = solution.PlusOne(new int[] { 9, 9, 8 });

            Console.ReadKey();
        }
    }
}
