using System;
using System.Collections.Generic;

namespace HouseRobberIII
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
        public int Rob(TreeNode root)
        {
            if (root == null)
            {
                return 0;
            }

            CalculateTotal(root);

            return root.val;
        }

        private void CalculateTotal(TreeNode node)
        {
            if (node == null)
            {
                return;
            }

            if (node.left != null)
            {
                CalculateTotal(node.left);
            }

            if (node.right != null)
            {
                CalculateTotal(node.right);
            }

            var totalChildValue = (node.left?.val ?? 0) + (node.right?.val ?? 0);
            var supplementedValue = GetTotalGrandchildValue(node) + node.val;

            node.val = Math.Max(totalChildValue, supplementedValue);
        }

        private int GetTotalGrandchildValue(TreeNode node)
        {
            var grandchildren = new List<TreeNode>
            {
                node?.left?.left,
                node?.left?.right,
                node?.right?.left,
                node?.right?.right
            };

            var highestValue = 0;
            foreach (var grandchild in grandchildren)
            {
                highestValue += grandchild?.val ?? 0;
            }

            return highestValue;
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
                left = new TreeNode
                {
                    val = 2,
                    right = new TreeNode(3)
                },
                right = new TreeNode
                {
                    val = 3,
                    right = new TreeNode(1)
                }
            };

            var treeTwo = new TreeNode
            {
                val = 3,
                left = new TreeNode
                {
                    val = 4,
                    left = new TreeNode(1),
                    right = new TreeNode(3)
                },
                right = new TreeNode
                {
                    val = 5,
                    right = new TreeNode(1)
                }
            };

            Console.WriteLine(solution.Rob(treeOne));
            Console.WriteLine(solution.Rob(treeTwo));

            Console.ReadKey();
        }
    }
}
