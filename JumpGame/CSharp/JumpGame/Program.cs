using System;

namespace JumpGame
{
    public class Solution
    {
        public bool CanJump(int[] nums)
        {
            if (nums.Length == 0)
            {
                return true;
            }

            var lastZeroIndex = -1;
            var canJump = true;
            for (var i = nums.Length - 2; i >= 0; i--)
            {
                if (lastZeroIndex > i)
                {
                    var distance = lastZeroIndex - i;
                    if (nums[i] > distance)
                    {
                        canJump = true;
                        lastZeroIndex = -1;
                    }
                }
                else if (nums[i] == 0)
                {
                    lastZeroIndex = i;
                    canJump = false;
                }
            }

            return canJump;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.CanJump(new int[] { 2, 3, 1, 1, 4 }));  // true
            Console.WriteLine(solution.CanJump(new int[] { 3, 2, 1, 0, 4 }));  // false
            Console.WriteLine(solution.CanJump(new int[] { 4, 2, 1, 0, 4 }));  // true

            Console.ReadKey();
        }
    }
}
