using System;
using System.Collections.Generic;

namespace BinaryTreeZigzagLevelOrderTraversal
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
        public IList<IList<int>> ZigzagLevelOrder(TreeNode root)
        {
            var result = new List<IList<int>>();

            if (root == null)
            {
                return result;
            }

            var queue = new Queue<TreeNode>();
            queue.Enqueue(root);
            var forwards = true;

            while (queue.Count > 0)
            {
                var levelCount = queue.Count;
                var order = new int[levelCount];

                if (forwards)
                {
                    for (int i = 0; i < levelCount; i++)
                    {
                        var node = queue.Dequeue();
                        if (node.left != null)
                        {
                            queue.Enqueue(node.left);
                        }

                        if (node.right != null)
                        {
                            queue.Enqueue(node.right);
                        }

                        order[i] = node.val;
                    }
                }
                else
                {
                    for (int i = levelCount - 1; i >=0; i--)
                    {
                        var node = queue.Dequeue();
                        if (node.left != null)
                        {
                            queue.Enqueue(node.left);
                        }

                        if (node.right != null)
                        {
                            queue.Enqueue(node.right);
                        }

                        order[i] = node.val;
                    }
                }

                forwards = !forwards;
                result.Add(order);
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
                val = 3,
                left = new TreeNode(9),
                right = new TreeNode
                {
                    val = 20,
                    left = new TreeNode(15),
                    right = new TreeNode(7)
                }
            };

            var resultOne = solution.ZigzagLevelOrder(treeOne);

            Console.ReadKey();
        }
    }
}
