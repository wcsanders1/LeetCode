using System;

namespace MedianOfTwoSortedArrays
{
    public class Solution
    {
        // I'm aware that the time complexity of this algorithm isn't what was asked. Shoot, sorry.
        public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            var totalLength = nums1.Length + nums2.Length;
            var newArray = new int[totalLength];

            var iOne = 0;
            var iTwo = 0;

            for (var i = 0; i < totalLength; i++)
            {
                if (iOne >= nums1.Length)
                {
                    newArray[i] = nums2[iTwo++];
                    continue;
                }

                if (iTwo >= nums2.Length)
                {
                    newArray[i] = nums1[iOne++];
                    continue;
                }

                if (nums1[iOne] <= nums2[iTwo])
                {
                    newArray[i] = nums1[iOne++];
                }
                else
                {
                    newArray[i] = nums2[iTwo++];
                }
            }

            var middle = totalLength / 2;
            if ((totalLength & 1) == 1)
            {
                return newArray[middle];
            }
            return (double)(newArray[middle] + newArray[middle - 1]) / 2;

        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.FindMedianSortedArrays(new int[] { 1, 3, 8, 9, 15 }, new int[] { 7, 11, 18, 19, 21, 25 }));
            Console.WriteLine(solution.FindMedianSortedArrays(new int[] { 1, 3 }, new int[] { 2 }));
            Console.WriteLine(solution.FindMedianSortedArrays(new int[] { 1, 2 }, new int[] { 3, 4 }));
            Console.WriteLine(solution.FindMedianSortedArrays(new int[] { 1, 3, 5 }, new int[] { 4, 6 }));
            Console.WriteLine(solution.FindMedianSortedArrays(new int[] { 5, 10 }, new int[] { 6, 11 }));
            Console.WriteLine(solution.FindMedianSortedArrays(new int[] { 10, 60, 61, 80, 85, 100 }, new int[] { 1, 2, 70, 81, 82, 90, 105 }));
            Console.WriteLine(solution.FindMedianSortedArrays(new int[] { 1, 2, 10, 60, 61, 70, 80, 81, 82, 85, 90, 100, 105 }, new int[] { 3 }));

            Console.ReadKey();
        }
    }
}
