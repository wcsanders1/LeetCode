using System;
using System.Collections.Generic;
using System.Linq;

namespace SubsetsII
{
    public class Solution
    {
        public IList<IList<int>> SubsetsWithDup(int[] nums)
        {
            var result = new List<IList<int>>();

            if (nums == null)
            {
                return result;
            }

            result.Add(new List<int>());

            Array.Sort(nums);

            var previousSubsets = new List<List<int>>();
            for (int i = 0; i < nums.Length; i++)
            {
                var currentNum = nums[i];
                if (i == 0)
                {
                    var subset = new List<int> { currentNum };
                    result.Add(subset);
                    previousSubsets = new List<List<int>> { subset };
                    continue;
                }

                List<List<int>> newSubsets;

                if (currentNum == nums[i - 1])
                {
                    newSubsets = previousSubsets.Select(s =>
                    {
                        var newSubset = new List<int> { currentNum };
                        newSubset.AddRange(s);

                        return newSubset;
                    }).ToList();
                }
                else
                {
                    newSubsets = result.Select(s =>
                    {
                        var newSubset = new List<int> { currentNum };
                        newSubset.AddRange(s);

                        return newSubset;
                    }).ToList();
                }

                previousSubsets = newSubsets;
                result.AddRange(newSubsets);
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var inputOne = new int[] { 1, 2, 2 };
            var inputTwo = new int[] { 1, 2, 3, 4 };

            var resultOne = solution.SubsetsWithDup(inputOne);
            var resultTwo = solution.SubsetsWithDup(inputTwo);

            Console.ReadKey();
        }
    }
}
