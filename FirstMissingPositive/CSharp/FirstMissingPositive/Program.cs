using System;

namespace FirstMissingPositive
{
    public class Solution
    {
        public int FirstMissingPositive(int[] nums)
        {
            for (var i = 0; i < nums.Length; i++)
            {
                var num = nums[i];
                if (num <= 0 ||
                    num >= nums.Length ||
                    num == nums[num - 1])
                {
                    continue;
                }

                var temp = nums[num - 1];
                nums[i] = temp;
                nums[num - 1] = num;

                i--;
            }

            for (var i = 0; i < nums.Length; i++)
            {
                if (nums[i] != i + 1)
                {
                    return i + 1;
                }
            }

            return nums.Length + 1;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            //Console.WriteLine(solution.FirstMissingPositive(new int[] { 1, 2, 0 }));
            //Console.WriteLine(solution.FirstMissingPositive(new int[] { 3, 4, -1, 1 }));
            //Console.WriteLine(solution.FirstMissingPositive(new int[] { 7, 8, 9, 11, 12 }));
            Console.WriteLine(solution.FirstMissingPositive(new int[] { 1, 3, 5, 5, 5, 7, 8, 9, 11, 12, 4, 3, 6 }));

            Console.ReadKey();
        }
    }
}
