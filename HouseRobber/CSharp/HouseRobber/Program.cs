using System;

namespace HouseRobber
{
    public class Solution
    {
        public int Rob(int[] nums)
        {
            if (nums == null || nums.Length == 0)
            {
                return 0;
            }

            if (nums.Length == 1)
            {
                return nums[0];
            }

            for (int i = nums.Length - 2; i >= 0; i--)
            {
                if (i == nums.Length - 2)
                {
                    nums[i] = Math.Max(nums[i], nums[i + 1]);
                }
                else
                {
                    nums[i] = Math.Max(nums[i + 1], nums[i] + nums[i + 2]);
                }
            }

            return nums[0];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.Rob(new int[] { 1, 2, 3, 1 }));
            Console.WriteLine(solution.Rob(new int[] { 2, 7, 9, 3, 1 }));
            Console.WriteLine(solution.Rob(new int[] { 2, 1, 1, 2 }));
            Console.WriteLine(solution.Rob(new int[] { 6, 6, 4, 8, 4, 3, 3, 10 }));
            Console.WriteLine(solution.Rob(new int[] { 2, 4, 8, 9, 9, 3 }));

            Console.ReadKey();
        }
    }
}
