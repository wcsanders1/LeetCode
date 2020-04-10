using System;

namespace _3SumClosest
{
    public class Solution
    {
        public int ThreeSumClosest(int[] nums, int target)
        {
            Array.Sort(nums);

            var result = nums[0] + nums[1] + nums[2];
            
            if (result == target)
            {
                return result;
            }

            for (var i = 0; i < nums.Length - 2; i++)
            {
                var num = nums[i];
                var start = i + 1;
                var end = nums.Length - 1;

                while (start < end)
                {
                    var tempResult = num + nums[start] + nums[end];
                    if (tempResult == target)
                    {
                        return target;
                    }

                    if (Math.Abs(target - tempResult) < Math.Abs(target - result))
                    {
                        result = tempResult;
                    }

                    if (tempResult > target)
                    {
                        end--;
                    }
                    else
                    {
                        start++;
                    }
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

            Console.WriteLine(solution.ThreeSumClosest(new int[] { -1, 2, 1, -4}, 1));

            Console.ReadKey();
        }
    }
}
