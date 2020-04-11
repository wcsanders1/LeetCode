using System;
using System.Collections.Generic;
using System.Linq;

namespace _4Sum
{
    public class Indexes
    {
        public int FirstIndex { get; set; }
        public int SecondIndex { get; set; }
    }

    public class Solution
    {
        public IList<IList<int>> FourSum(int[] nums, int target)
        {
            var sums = new Dictionary<int, List<Indexes>>();

            Array.Sort(nums);

            for (var a = 0; a < nums.Length; a++)
            {
                for (int b = a + 1; b < nums.Length; b++)
                {
                    var sum = nums[a] + nums[b];
                    var indexes = new Indexes { FirstIndex = a, SecondIndex = b };
                    if (!sums.ContainsKey(sum))
                    {
                        sums.Add(sum, new List<Indexes> { indexes });
                    }
                    else
                    {
                        sums[sum].Add(indexes);
                    }
                }
            }

            IList<IList<int>> result = new List<IList<int>>();

            foreach (var kv in sums)
            {
                var neededAmount = target - kv.Key;
                var lessThanIndexes = kv.Value;

                if (sums.TryGetValue(neededAmount, out var greaterThanIndexes))
                {
                    foreach (var lesserIndex in lessThanIndexes)
                    {
                        foreach (var greaterIndex in greaterThanIndexes)
                        {
                            if (lesserIndex.FirstIndex == greaterIndex.FirstIndex ||
                                lesserIndex.FirstIndex == greaterIndex.SecondIndex ||
                                lesserIndex.SecondIndex == greaterIndex.FirstIndex ||
                                lesserIndex.SecondIndex == greaterIndex.SecondIndex)
                            {
                                continue;
                            }

                            var newResult = new List<int>
                            {
                                nums[lesserIndex.FirstIndex],
                                nums[lesserIndex.SecondIndex],
                                nums[greaterIndex.FirstIndex],
                                nums[greaterIndex.SecondIndex]
                            };

                            newResult.Sort();

                            if (result.Any(list => 
                                list[0] == newResult[0] &&
                                list[1] == newResult[1] &&
                                list[2] == newResult[2] &&
                                list[3] == newResult[3]))
                            {
                                continue;
                            }

                            result.Add(newResult);
                        }

                    }
                }
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.FourSum(new int[] { 1, 0, -1, 0, -2, 2 }, 0);
            var result2 = solution.FourSum(new int[] { 0, 0, 0, 0 }, 0);

            Console.ReadKey();
        }
    }
}
