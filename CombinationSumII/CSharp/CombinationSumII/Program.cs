using System;
using System.Collections.Generic;
using System.Linq;

namespace CombinationSumII
{
    public class Solution
    {
        public IList<IList<int>> CombinationSum2(int[] candidates, int target)
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
                if (i > index && candidates[i] == candidates[i - 1])
                {
                    continue;
                }

                var num = candidates[i];
                if (num > target)
                {
                    return;
                }

                path.Push(num);
                GetCombinations(candidates, target - num, i + 1, result, path);
                path.Pop();
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.CombinationSum2(new int[] { 10, 1, 2, 7, 6, 1, 5 }, 8);
            var result2 = solution.CombinationSum2(new int[] { 2, 5, 2, 1, 2 }, 5);

            Console.ReadKey();
        }
    }
}
