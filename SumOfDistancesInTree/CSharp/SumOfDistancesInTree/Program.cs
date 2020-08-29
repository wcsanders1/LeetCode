using System;
using System.Collections.Generic;

namespace SumOfDistancesInTree
{
    public class Solution
    {
        private int[] Result { get; set; }
        private int[] Count { get; set; }
        private List<int>[] Graph { get; set; }

        public int[] SumOfDistancesInTree(int N, int[][] edges)
        {
            Result = new int[N];
            Count = new int[N];
            Graph = new List<int>[N];

            for (int i = 0; i < N; i++)
            {
                Graph[i] = new List<int>();
            }

            foreach (var edge in edges)
            {
                Graph[edge[0]].Add(edge[1]);
                Graph[edge[1]].Add(edge[0]);
            }

            PostOrder(0, -1);
            PreOrder(0, -1);

            return Result;
        }

        private void PostOrder(int node, int parent)
        {
            foreach (var next in Graph[node])
            {
                if (next == parent)
                {
                    continue;
                }

                PostOrder(next, node);

                Count[node] += Count[next];
                Result[node] += Result[next] + Count[next];
            }

            Count[node]++;
        }

        private void PreOrder(int node, int parent)
        {
            foreach (var next in Graph[node])
            {
                if (next == parent)
                {
                    continue;
                }

                Result[next] = Result[node] - Count[next] + Graph.Length - Count[next];
                PreOrder(next, node);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var resultOne = solution.SumOfDistancesInTree(6, new int[][]
            {
                new int[]{0, 1},
                new int[]{0, 2},
                new int[]{2, 3},
                new int[]{2, 4},
                new int[]{2, 5},
            });

            Console.ReadKey();
        }
    }
}
