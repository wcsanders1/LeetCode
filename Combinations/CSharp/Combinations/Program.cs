using System;
using System.Collections.Generic;
using System.Linq;

namespace Combinations
{
    public class Solution
    {
        public IList<IList<int>> Combine(int n, int k)
        {
            var result = new List<IList<int>>();

            if (n == 0 || k == 0)
            {
                return result;
            }

            if (k == 1)
            {
                for (int i = 1; i <= n; i++)
                {
                    result.Add(new List<int> { i });
                }
                return result;
            }

            var visited = new bool[n + 1];
            GetCombinations(1, 2, n, k, result, new List<int> { 1 }, visited);

            return result;
        }

        private void GetCombinations(int start, int next, int end, int limit, List<IList<int>> result, List<int> current, bool[] visited)
        {
            if (current.Count == limit)
            {
                result.Add(current);
                return;
            }

            for (var i = next; i <= end; i++)
            {
                var combination = current.Select(i => i).ToList();
                combination.Add(i);
                GetCombinations(start, i + 1, end, limit, result, combination, visited);
            }

            for (var i = start + 1; i <= end; i++)
            {
                if (visited[i])
                {
                    continue;
                }

                visited[i] = true;

                GetCombinations(i, i + 1, end, limit, result, new List<int> { i }, visited);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.Combine(4, 2);
            var result2 = solution.Combine(4, 3);
            var result3 = solution.Combine(2, 1);

            Console.ReadKey();
        }
    }
}
