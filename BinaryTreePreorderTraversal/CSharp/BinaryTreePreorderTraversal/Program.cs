using System;
using System.Collections.Generic;

namespace BinaryTreePreorderTraversal
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
        public IList<int> PreorderTraversal(TreeNode root)
        {
            var result = new List<int>();

            if (root == null)
            {
                return result;
            }

            var nodes = new Stack<TreeNode>();

            nodes.Push(root);

            while (nodes.Count > 0)
            {
                var node = nodes.Pop();

                result.Add(node.val);

                if (node.right != null)
                {
                    nodes.Push(node.right);
                }

                if (node.left != null)
                {
                    nodes.Push(node.left);
                }
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var treeOne = new TreeNode
            {
                val = 1,
                right = new TreeNode
                {
                    val = 2,
                    left = new TreeNode
                    {
                        val = 3
                    }
                }
            };

            var treeTwo = new TreeNode
            {
                val = 1,
                left = new TreeNode
                {
                    val = 2,
                    left = new TreeNode
                    {
                        val = 4
                    },
                    right = new TreeNode
                    {
                        val = 5
                    }
                },
                right = new TreeNode
                {
                    val = 3
                }
            };

            var resultOne = solution.PreorderTraversal(treeOne);
            var resultTwo = solution.PreorderTraversal(treeTwo);

            Console.ReadKey();
        }
    }
}
