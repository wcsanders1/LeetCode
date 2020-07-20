using System;
using System.Collections.Generic;

namespace UniqueBinarySearchTreesII
{
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public class Solution
    {
        public IList<TreeNode> GenerateTrees(int n)
        {
            if (n == 0)
            {
                return new List<TreeNode>();
            }

            return GenerateTrees(1, n);
        }

        private List<TreeNode> GenerateTrees(int s, int e)
        {
            var trees = new List<TreeNode>();
            if (s > e)
            {
                trees.Add(null);

                return trees;
            }

            for (int i = s; i <= e; i++)
            {
                var leftTrees = GenerateTrees(s, i - 1);
                var rightTrees = GenerateTrees(i + 1, e);

                foreach (var leftTree in leftTrees)
                {
                    foreach (var rightTree in rightTrees)
                    {
                        var root = new TreeNode(i)
                        {
                            left = leftTree,
                            right = rightTree
                        };

                        trees.Add(root);
                    }
                }
            }

            return trees;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var resultOne = solution.GenerateTrees(30);

            Console.ReadKey();
        }
    }
}
