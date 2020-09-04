using System;
using System.Collections.Generic;

namespace MinimumHeightTrees
{
    public class Solution
    {
        public IList<int> FindMinHeightTrees(int n, int[][] edges)
        {
            if (n == 0 || edges == null || edges.Length == 0)
            {
                return new List<int> { 0 };
            }

            var nodes = new Dictionary<int, List<int>>();

            foreach (var edge in edges)
            {
                if (!nodes.ContainsKey(edge[0]))
                {
                    nodes.Add(edge[0], new List<int> { edge[1] });
                }
                else
                {
                    nodes[edge[0]].Add(edge[1]);
                }

                if (!nodes.ContainsKey(edge[1]))
                {
                    nodes.Add(edge[1], new List<int> { edge[0] });
                }
                else
                {
                    nodes[edge[1]].Add(edge[0]);
                }
            }

            var leaves = new List<int>();
            for (int i = 0; i < n; i++)
            {
                if (nodes[i].Count == 1)
                {
                    leaves.Add(i);
                }
            }

            while (n > 2)
            {
                n -= leaves.Count;
                var newLeaves = new List<int>();
                foreach (var leaf in leaves)
                {
                    var j = nodes[leaf][0];
                    nodes[j].Remove(leaf);

                    if (nodes[j].Count == 1)
                    {
                        newLeaves.Add(j);
                    }
                }

                leaves = newLeaves;
            }

            return leaves;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var resultOne = solution.FindMinHeightTrees(4, new int[][]
            {
               new int[] {1, 0 },
               new int[] {1, 2 },
               new int[] {1, 3 }
            });

            var resultTwo = solution.FindMinHeightTrees(6, new int[][]
            {
                new int[] {3, 0},
                new int[] {3, 1},
                new int[] {3, 2},
                new int[] {3, 4},
                new int[] {5, 4},
            });

            Console.ReadKey();
        }
    }
}
