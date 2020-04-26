using System;
using System.Collections.Generic;
using System.Linq;

namespace PermutationsII
{
    public class Solution
    {
        public IList<IList<int>> PermuteUnique(int[] nums)
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

            var tried = new HashSet<int>();
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

                if (tried.Contains(nums[i]))
                {
                    continue;
                }

                tried.Add(nums[i]);

                GetPermutations(nums, permutations, index + 1, nextVisited, nextPermutation);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.PermuteUnique(new int[] { 1, 1, 2 });
            
            Console.ReadKey();
        }
    }
}
