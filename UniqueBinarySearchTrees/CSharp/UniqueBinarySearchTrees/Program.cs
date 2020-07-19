using System;
using System.Collections.Generic;

namespace UniqueBinarySearchTrees
{
    public class TreeNode
    {
        public int Value { get; set; }
        public TreeNode LeftNode { get; set; }
        public TreeNode RightNode { get; set; }

        public TreeNode(int value)
        {
            Value = value;
        }
    }

    public class Solution
    {
        public int NumTrees(int n)
        {
            var results = new int[n + 1];
            results[0] = 1;
            results[1] = 1;

            for (int i = 2; i <= n; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    results[i] += results[j - 1] * results[i - j];
                }
            }

            return results[n];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.NumTrees(2));
            Console.WriteLine(solution.NumTrees(3));
            Console.WriteLine(solution.NumTrees(4));
            Console.WriteLine(solution.NumTrees(9));
            Console.WriteLine(solution.NumTrees(10));

            Console.ReadKey();
        }
    }
}
