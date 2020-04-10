using System;
using System.Collections.Generic;

namespace _3Sum
{
    public class Solution
    {
        public IList<IList<int>> ThreeSum(int[] nums)
        {
            IList<IList<int>> result = new List<IList<int>>();

            Array.Sort(nums);

            var table = new HashSet<int>();
            var negativeNumbers = new List<int>();
            var positiveNumbers = new List<int>();
            var zeroAmount = 0;

            for (var i = 0; i < nums.Length; i++)
            {
                var number = nums[i];
                if (number == 0)
                {
                    zeroAmount++;
                }

                if (!table.Contains(number))
                {
                    table.Add(number);
                }

                if (number < 0)
                {
                    negativeNumbers.Add(number);
                }
                else
                {
                    positiveNumbers.Add(number);
                }
            }

            if (zeroAmount >= 3)
            {
                result.Add(new List<int> { 0, 0, 0 });
            }

            for (var outter = 0; outter < negativeNumbers.Count; outter++)
            {
                if (outter > 0)
                {
                    while (outter < negativeNumbers.Count && negativeNumbers[outter - 1] == negativeNumbers[outter])
                    {
                        outter++;
                    }
                    if (outter >= negativeNumbers.Count)
                    {
                        break;
                    }
                }

                for (var inner = outter + 1; inner < negativeNumbers.Count; inner++)
                {
                    if (inner > outter + 1)
                    {
                        while (inner < negativeNumbers.Count && negativeNumbers[inner - 1] == negativeNumbers[inner])
                        {
                            inner++;
                        }
                        if (inner >= negativeNumbers.Count)
                        {
                            break;
                        }
                    }

                    var partialSum = negativeNumbers[outter] + negativeNumbers[inner];
                    var neededValue = partialSum * -1;
                    if (table.Contains(neededValue))
                    {
                        result.Add(new List<int> { negativeNumbers[outter], negativeNumbers[inner], neededValue });
                    }
                }
            }

            for (var outter = 0; outter < positiveNumbers.Count; outter++)
            {
                if (outter > 0)
                {
                    while (outter < positiveNumbers.Count && positiveNumbers[outter - 1] == positiveNumbers[outter])
                    {
                        outter++;
                    }
                    if (outter >= positiveNumbers.Count)
                    {
                        break;
                    }
                }

                for (var inner = outter + 1; inner < positiveNumbers.Count; inner++)
                {
                    if (inner > outter + 1)
                    {
                        while (inner < positiveNumbers.Count && positiveNumbers[inner - 1] == positiveNumbers[inner])
                        {
                            inner++;
                        }
                        if (inner >= positiveNumbers.Count)
                        {
                            break;
                        }
                    }

                    var partialSum = positiveNumbers[outter] + positiveNumbers[inner];
                    var neededValue = partialSum * -1;
                    if (neededValue != 0 && table.Contains(neededValue))
                    {
                        result.Add(new List<int> { positiveNumbers[outter], positiveNumbers[inner], neededValue });
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

            var result1 = solution.ThreeSum(new int[] { -1, 0, 1, 2, -1, -4 });
            var result2 = solution.ThreeSum(new int[] { -1, 0, 1, 0 });

            Console.ReadKey();
        }
    }
}
