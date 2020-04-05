using System;
using System.Collections.Generic;

namespace TwoSum
{
    public class Solution
    {
        public int[] TwoSum(int[] nums, int target)
        {
            var kv = new Dictionary<int, int>();

            for (var i = 0; i < nums.Length; i++)
            {
                var number = nums[i];
                var neededNumber = target - number;
                if (kv.TryGetValue(neededNumber, out var requiredIndex))
                {
                    return new int[] { requiredIndex, i };
                }
                if (!kv.ContainsKey(number))
                {
                    kv.Add(number, i);
                }
            }

            return new int[] { 0, 0 };
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.TwoSum(new int[] { 2, 7, 11, 15 }, 9);

            Console.ReadKey();
        }
    }
}
