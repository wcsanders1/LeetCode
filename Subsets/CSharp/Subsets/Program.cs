using System;
using System.Collections.Generic;
using System.Linq;

namespace Subsets
{
    public class Solution
    {
        public IList<IList<int>> Subsets(int[] nums)
        {
            var result = new List<IList<int>> { new List<int>() };

            GetSubsets(result, 0, nums, new List<int>());

            return result;
        }

        private void GetSubsets(List<IList<int>> subsets, int start, int[] nums, List<int> newSubset)
        {
            if (start >= nums.Length)
            {
                return;
            }

            for (var i = start; i < nums.Length; i++)
            {
                var subsetCopy = newSubset.Select(i => i).ToList();
                subsetCopy.Add(nums[i]);
                subsets.Add(subsetCopy);
                GetSubsets(subsets, i + 1, nums, subsetCopy);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.Subsets(new int[] { 1, 2 });
            var result2 = solution.Subsets(new int[] { 1, 2, 3 });

            Console.ReadKey();
        }
    }
}
