using System;
using System.Linq;

namespace ShortestPathVisitingAllNodes
{
    public class Visited
    {
        private bool[] NodeVisited { get; }
        private int NumberVisited { get; set; }

        public Visited(int nodeAmount)
        {
            NodeVisited = new bool[nodeAmount];
        }

        public void SetVisited(int node)
        {
            if (!NodeVisited[node])
            {
                NodeVisited[node] = true;
                NumberVisited++;
            }
        }

        public bool WasVisited(int node)
        {
            return NodeVisited[node];
        }

        public bool AllVisited()
        {
            return NumberVisited == NodeVisited.Length;
        }
    }

    public class Node
    {
        public int Value { get; set; }
        public Node[] Connections { get; set; }

        public Node(int value)
        {
            Value = value;
        }
    }

    public class Graph
    {
        public Node[] Nodes { get; set; }

        public Graph(int nodeAmount)
        {
            Nodes = new Node[nodeAmount];

            for (int i = 0; i < nodeAmount; i++)
            {
                Nodes[i] = new Node(i);
            }
        }
    }

    public class Solution
    {
        public int ShortestPathLength(int[][] graph)
        {
            if (graph == null || graph.Length == 0)
            {
                return 0;
            }

            var connectedGraph = new Graph(graph.Length);

            for (int i = 0; i < graph.Length; i++)
            {
                var node = connectedGraph.Nodes[i];
                node.Connections = new Node[graph[i].Length];

                for (int j = 0; j < graph[i].Length; j++)
                {
                    node.Connections[j] = connectedGraph.Nodes[graph[i][j]];
                }
            }

            var result = 0;

            foreach (var connection in connectedGraph.Nodes)
            {
                var newResult = VisitAllConnections(connection, new Visited(graph.Length));
                if (result == 0)
                {
                    result = newResult;
                }

                if (newResult < result)
                {
                    result = newResult;
                }
            }

            return result;
        }

        private int VisitAllConnections(Node node, Visited visited, int traversals = 0)
        {
            visited.SetVisited(node.Value);

            var orderedConnections = node.Connections.OrderBy(c => c.Connections.Length).ToArray();

            foreach (var connection in orderedConnections)
            {
                if (visited.WasVisited(connection.Value))
                {
                    continue;
                }

                traversals = VisitAllConnections(connection, visited, traversals + 1);
            }

            if (visited.AllVisited())
            {
                return traversals;
            }

            return traversals + 1;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.ShortestPathLength(new int[][]
                {new []{1, 2, 3}, new [] {0}, new int[]{0}, new int[]{0}}));

            Console.WriteLine(solution.ShortestPathLength(new int[][]
                {new []{1}, new [] {0, 2, 4}, new int[]{1, 3, 4}, new int[]{2}, new int[]{1, 2 } }));

            Console.WriteLine(solution.ShortestPathLength(new int[][]
                {new []{1}, new [] {0, 2, 4}, new int[]{1, 3}, new int[]{2}, new int[]{1, 5 }, new int[] {4 } }));

            Console.ReadKey();
        }
    }
}
