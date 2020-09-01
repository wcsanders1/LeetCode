using System;
using System.Collections.Generic;
using System.Linq;

namespace MinimumAbsoluteDifferenceInBST
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
        public int GetMinimumDifference(TreeNode root)
        {
            var uniqueValues = new HashSet<int>();
            GetUniqueValues(root, uniqueValues);

            var orderedUniqueValues = uniqueValues.OrderByDescending(v => v).ToList();

            var result = int.MaxValue;

            for (int i = 0; i < orderedUniqueValues.Count - 1; i++)
            {
                var tempResult = orderedUniqueValues[i] - orderedUniqueValues[i + 1];
                if (tempResult < result)
                {
                    result = tempResult;
                }
            }

            return result;
        }

        private void GetUniqueValues(TreeNode node, HashSet<int> values)
        {
            if (node == null)
            {
                return;
            }

            if (node.left != null)
            {
                GetUniqueValues(node.left, values);
            }

            if (node.right != null)
            {
                GetUniqueValues(node.right, values);
            }

            if (!values.Contains(node.val))
            {
                values.Add(node.val);
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
                val = 1,
                right = new TreeNode
                {
                    val = 3,
                    left = new TreeNode(2)
                }
            };

            Console.WriteLine(solution.GetMinimumDifference(treeOne));

            Console.ReadKey();
        }
    }
}
