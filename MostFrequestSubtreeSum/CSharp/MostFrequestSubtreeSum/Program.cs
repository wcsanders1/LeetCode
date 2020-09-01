using System;
using System.Collections.Generic;

namespace MostFrequestSubtreeSum
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
        public int[] FindFrequentTreeSum(TreeNode root)
        {
            var totals = new Dictionary<int, int>();
            GetTotals(root, totals);

            var result = new List<int>();
            var highestTotal = 0;

            foreach (var kv in totals)
            {
                if (kv.Value > highestTotal)
                {
                    highestTotal = kv.Value;
                    result.Clear();
                    result.Add(kv.Key);
                }
                else if (kv.Value == highestTotal)
                {
                    result.Add(kv.Key);
                }
            }

            return result.ToArray();
        }

        private void GetTotals(TreeNode node, Dictionary<int, int> totals)
        {
            if (node == null)
            {
                return;
            }

            if (node.left != null)
            {
                GetTotals(node.left, totals);
            }

            if (node.right != null)
            {
                GetTotals(node.right, totals);
            }

            node.val += (node.left?.val ?? 0) + (node.right?.val ?? 0);

            if (!totals.ContainsKey(node.val))
            {
                totals.Add(node.val, 1);
            }
            else
            {
                totals[node.val]++;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var treeOne = new TreeNode
            {
                val = 5,
                left = new TreeNode(2),
                right = new TreeNode(-3)
            };

            var treeTwo = new TreeNode
            {
                val = 5,
                left = new TreeNode(2),
                right = new TreeNode(-5)
            };

            var resultOne = solution.FindFrequentTreeSum(treeOne);
            var resultTwo = solution.FindFrequentTreeSum(treeTwo);

            Console.ReadKey();
        }
    }
}
