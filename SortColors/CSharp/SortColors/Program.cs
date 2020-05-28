using System;

namespace SortColors
{
    public class Solution
    {
        public void SortColors(int[] nums)
        {
            for (var i = 0; i < nums.Length; i++)
            {
                var currentNum = nums[i];
                var x = i;
                while (x > 0 && currentNum < nums[x - 1])
                {
                    nums[x] = nums[x - 1];
                    nums[x - 1] = currentNum;
                    x--;
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var array1 = new int[] { 2, 0, 2, 1, 1, 0 };

            solution.SortColors(array1);

            Console.ReadKey();
        }
    }
}
