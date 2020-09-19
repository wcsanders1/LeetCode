using System;
using System.Collections.Generic;

namespace Triangle
{
    public class Solution
    {
        public int MinimumTotal(IList<IList<int>> triangle)
        {
            if (triangle == null || triangle.Count == 0)
            {
                return 0;
            }

            if (triangle.Count == 1)
            {
                return triangle[0][0];
            }

            for (int i = triangle.Count - 2; i >= 0; i--)
            {
                var currentRow = triangle[i];
                var lowerRow = triangle[i + 1];

                for (int j = 0; j < currentRow.Count; j++)
                {
                    var currentNum = currentRow[j];
                    currentRow[j] = Math.Min(currentNum + lowerRow[j], currentNum + lowerRow[j + 1]);
                }
            }

            return triangle[0][0];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var triangleOne = new List<IList<int>>
            {
                new List<int>{2},
                new List<int>{3, 4,},
                new List<int>{6, 5, 7},
                new List<int>{4, 1, 8, 3}
            };

            Console.WriteLine(solution.MinimumTotal(triangleOne));

            Console.ReadKey();
        }
    }
}
