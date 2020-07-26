using System;
using System.Collections.Generic;

namespace BinaryTreeInorderTraversal
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
        public IList<int> InorderTraversal(TreeNode root)
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
                var node = nodes.Peek();

                if (node.left != null)
                {
                    var leftNode = node.left;
                    node.left = null;
                    while (leftNode != null)
                    {
                        nodes.Push(leftNode);
                        var oldNode = leftNode;
                        leftNode = leftNode.left;
                        oldNode.left = null;
                    }

                    continue;
                }
                else
                {
                    node = nodes.Pop();
                    result.Add(node.val);
                    if (node.right != null)
                    {
                        nodes.Push(node.right);
                    }
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

            var resultOne = solution.InorderTraversal(treeOne);
            var resultTwo = solution.InorderTraversal(treeTwo);

            Console.ReadKey();
        }
    }
}
