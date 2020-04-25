using System;

namespace JumpGameII
{
    public class Solution
    {
        public int Jump(int[] nums)
        {
            if (nums.Length <= 1)
            {
                return 0;
            }

            if (nums[0] == nums.Length)
            {
                return 1;
            }

            var jumps = new int[nums.Length];
            for (var i = nums.Length - 1; i >= 0; i--)
            {
                if (i == nums.Length - 1)
                {
                    jumps[i] = 0;
                    continue;
                }

                var jumpsAllowed = nums[i];
                var leastJumps = nums.Length - i;
                for (int j = 1; j <= jumpsAllowed; j++)
                {
                    var nextJump = j + i;
                    if (nextJump >= jumps.Length)
                    {
                        break;
                    }

                    var jumpAmount = jumps[nextJump] + 1;
                    if (jumpAmount < leastJumps)
                    {
                        leastJumps = jumpAmount;
                    }

                    if (leastJumps == 1)
                    {
                        break;
                    }
                }

                if (nums[0] == i && leastJumps == 1)
                {
                    return 2;
                }

                jumps[i] = leastJumps;
            }

            return jumps[0];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.Jump(new int[] { 2, 3, 1, 1, 4 })); // 2
            Console.WriteLine(solution.Jump(new int[] { 2, 3, 0, 1, 4 })); // 2
            Console.WriteLine(solution.Jump(new int[] { 2 })); // 0
            Console.WriteLine(solution.Jump(new int[] { 2, 4 })); // 1
            
            Console.ReadKey();
        }
    }
}
