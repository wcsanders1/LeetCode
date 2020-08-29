using System;
using System.Linq;

namespace HouseRobberII
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

            var robLastHouse = nums.Skip(1).Select(n => n).ToArray();
            var robFirstHouse = nums.Take(nums.Length - 1).Select(n => n).ToArray();

            for (int i = robFirstHouse.Length - 2; i >= 0; i--)
            {
                if (i == robFirstHouse.Length - 2)
                {
                    robFirstHouse[i] = Math.Max(robFirstHouse[i], robFirstHouse[i + 1]);
                }
                else
                {
                    robFirstHouse[i] = Math.Max(robFirstHouse[i + 1], robFirstHouse[i] + robFirstHouse[i + 2]);
                }
            }

            for (int i = robLastHouse.Length - 2; i >= 0; i--)
            {
                if (i == robLastHouse.Length - 2)
                {
                    robLastHouse[i] = Math.Max(robLastHouse[i], robLastHouse[i + 1]);
                }
                else
                {
                    robLastHouse[i] = Math.Max(robLastHouse[i + 1], robLastHouse[i] + robLastHouse[i + 2]);
                }
            }

            return Math.Max(robFirstHouse[0], robLastHouse[0]);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.Rob(new int[] { 2, 3, 2}));
            Console.WriteLine(solution.Rob(new int[] { 1, 2, 3, 1 }));
            Console.WriteLine(solution.Rob(new int[] { 2, 7, 9, 3, 1 }));

            Console.ReadKey();
        }
    }
}
