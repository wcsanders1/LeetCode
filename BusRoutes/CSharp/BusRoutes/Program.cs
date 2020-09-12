using System;
using System.Collections.Generic;
using System.Linq;

namespace BusRoutes
{
    public class Solution
    {
        public int NumBusesToDestination(int[][] routes, int S, int T)
        {
            var graph = new Dictionary<int, List<int>>();
            foreach (var route in routes)
            {
                var distinctRoutes = route.Distinct().ToArray();
                for (var i = 0; i < distinctRoutes.Length; i++)
                {
                    var stop = distinctRoutes[i];
                    if (!graph.ContainsKey(stop))
                    {
                        graph.Add(stop, new List<int>());
                    }

                    graph[stop].AddRange(distinctRoutes.Where((r, j) => j != i).ToList());
                }
            }

            return GetNumBuses(graph, S, T);
        }

        private int GetNumBuses(Dictionary<int, List<int>> graph, int S, int T)
        {
            if (S == T)
            {
                return 0;
            }

            var queue = new Queue<(int, int)>();
            queue.Enqueue((S, 1));
            var visited = new HashSet<int>();

            while (queue.Count > 0)
            {
                var (stop, busses) = queue.Dequeue();
                var stops = graph[stop];

                if (!visited.Contains(stop))
                {
                    visited.Add(stop);
                }

                foreach (var nextStop in stops)
                {
                    if (nextStop == T)
                    {
                        return busses;
                    }

                    if (!visited.Contains(nextStop))
                    {
                        visited.Add(nextStop);
                        queue.Enqueue((nextStop, busses + 1));
                    }
                }
            }

            return -1;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.NumBusesToDestination(new int[][]
            {
                new int [] {1, 2, 7 },
                new int [] {3, 6, 7}
            }, 1, 6));

            Console.ReadKey();
        }
    }
}
