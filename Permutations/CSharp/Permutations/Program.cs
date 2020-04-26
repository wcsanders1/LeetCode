using System;
using System.Collections.Generic;
using System.Linq;

namespace Permutations
{
    public class Solution
    {
        public IList<IList<int>> Permute(int[] nums)
        {
            var permutations = new List<IList<int>>();

            GetPermutations(nums, permutations);

            return permutations;
        }

        private void GetPermutations(int[] nums, List<IList<int>> permutations, int index = 0, bool[] visited = null, List<int> newPermutation = null)
        {
            if (index >= nums.Length)
            {
                permutations.Add(newPermutation);
                return;
            }

            for (int i = 0; i < nums.Length; i++)
            {
                bool[] nextVisited;
                if (visited == null)
                {
                    nextVisited = new bool[nums.Length];
                }
                else
                {
                    nextVisited = visited.Select(v => v).ToArray();
                }

                if (nextVisited[i])
                {
                    continue;
                }

                nextVisited[i] = true;

                List<int> nextPermutation;
                if (newPermutation == null)
                {
                    nextPermutation = new List<int>();
                }
                else
                {
                    nextPermutation = newPermutation.Select(d => d).ToList();
                }

                nextPermutation.Add(nums[i]);
                GetPermutations(nums, permutations, index + 1, nextVisited, nextPermutation);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.Permute(new int[] { 1, 2 });
            var result2 = solution.Permute(new int[] { 1, 2, 3 });
            var result3 = solution.Permute(new int[] { 1, 2, 3, 4 });

            Console.ReadKey();
        }
    }
}
