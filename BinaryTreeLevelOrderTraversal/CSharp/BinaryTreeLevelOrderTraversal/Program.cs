using System;
using System.Collections.Generic;

namespace BinaryTreeLevelOrderTraversal
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
        public IList<IList<int>> LevelOrder(TreeNode root)
        {
            var result = new List<IList<int>>();

            if (root == null)
            {
                return result;
            }

            var queue = new Queue<(TreeNode, int)>();
            queue.Enqueue((root, 1));

            while (queue.Count > 0)
            {
                var (node, level) = queue.Dequeue();
                
                if (level > result.Count)
                {
                    result.Add(new List<int>());
                }

                result[level - 1].Add(node.val);

                if (node.left != null)
                {
                    queue.Enqueue((node.left, level + 1));
                }

                if (node.right != null)
                {
                    queue.Enqueue((node.right, level + 1));
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
                val = 3,
                left = new TreeNode(9),
                right = new TreeNode
                {
                    val = 20,
                    left = new TreeNode(15),
                    right = new TreeNode(7)
                }
            };

            var resultOne = solution.LevelOrder(treeOne);

            Console.ReadKey();
        }
    }
}
