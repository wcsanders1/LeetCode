using System;

namespace CanMakeArithmeticProgression
{
    public class Solution
    {
        public bool CanMakeArithmeticProgression(int[] arr)
        {
            if (arr == null || arr.Length < 2)
            {
                return false;
            }

            if (arr.Length == 2)
            {
                return true;
            }

            Array.Sort(arr);

            var diff = arr[1] - arr[0];
            for (int i = 2; i < arr.Length; i++)
            {
                if (arr[i] - arr[i - 1] != diff)
                {
                    return false;
                }
            }

            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.CanMakeArithmeticProgression(new int[] { 3, 5, 1 }));
            Console.WriteLine(solution.CanMakeArithmeticProgression(new int[] { 1, 2, 4 }));
            Console.WriteLine(solution.CanMakeArithmeticProgression(new int[] { 13, 12, -12, 9, 9, 16, 7, -10, -20, 0, 18, -1, -20, -10, -8, 15, 15, 16, 2, 15 }));


            Console.ReadKey();
        }
    }
}
