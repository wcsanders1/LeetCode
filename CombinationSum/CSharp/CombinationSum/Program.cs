using System;
using System.Collections.Generic;
using System.Linq;

namespace CombinationSum
{
    public class Solution
    {
        public IList<IList<int>> CombinationSum(int[] candidates, int target)
        {
            var result = new List<IList<int>>();

            if (candidates == null || candidates.Length == 0)
            {
                return result;
            }

            Array.Sort(candidates);

            var path = new Stack<int>();

            GetCombinations(candidates, target, 0, result, path);

            return result;
        }

        private void GetCombinations(int[] candidates, int target, int index, IList<IList<int>> result, Stack<int> path)
        {
            if (target == 0)
            {
                result.Add(path.ToList());
                return;
            }

            for (var i = index; i < candidates.Length; i++)
            {
                var num = candidates[i];
                if (num > target)
                {
                    return;
                }

                path.Push(num);
                GetCombinations(candidates, target - num, i, result, path);
                path.Pop();
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.CombinationSum(new int[] { 2, 3, 6, 7 }, 7);
            var result2 = solution.CombinationSum(new int[] { 2, 3, 5 }, 8);

            Console.ReadLine();
        }
    }
}
