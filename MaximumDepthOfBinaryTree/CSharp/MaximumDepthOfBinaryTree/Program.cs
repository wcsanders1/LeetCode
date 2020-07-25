using System;

namespace MaximumDepthOfBinaryTree
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
        public int MaxDepth(TreeNode root)
        {
            return GetMaxDepth(root);
        }

        private int GetMaxDepth(TreeNode node, int currentDepth = 0)
        {
            if (node == null)
            {
                return currentDepth;
            }

            currentDepth++;

            var leftDepth = GetMaxDepth(node.left, currentDepth);
            var rightDepth = GetMaxDepth(node.right, currentDepth);

            return Math.Max(leftDepth, rightDepth);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadKey();
        }
    }
}
