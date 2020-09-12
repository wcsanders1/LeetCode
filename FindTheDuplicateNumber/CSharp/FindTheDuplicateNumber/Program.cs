using System;

namespace FindTheDuplicateNumber
{
    public class Solution
    {
        public int FindDuplicate(int[] nums)
        {
            if (nums == null || nums.Length == 0)
            {
                return 0;
            }

            var slow = nums[0];
            var fast = nums[nums[0]];

            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[fast];
            }

            return slow;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.FindDuplicate(new int[] { 1, 3, 4, 2, 2 }));
            Console.WriteLine(solution.FindDuplicate(new int[] { 3, 1, 3, 4, 2 }));
            Console.WriteLine(solution.FindDuplicate(new int[] { 1, 1 }));
            Console.WriteLine(solution.FindDuplicate(new int[] { 1, 1, 2 }));
            Console.WriteLine(solution.FindDuplicate(new int[] { 2, 2, 2, 2 }));
            Console.WriteLine(solution.FindDuplicate(new int[] { 1, 4, 4, 2, 3 }));

            Console.ReadKey();
        }
    }
}
