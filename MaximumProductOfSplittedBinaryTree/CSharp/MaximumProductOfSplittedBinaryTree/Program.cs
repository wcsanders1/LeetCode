using System;

namespace MaximumProductOfSplittedBinaryTree
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
        public int MaxProduct(TreeNode root)
        {
            const int mod = 1000000007;

            if (root == null)
            {
                return 0;
            }

            SetTotals(root);

            var result = GetHighestProduct(root, root.val);

            return (int)(result % mod);
        }

        private void SetTotals(TreeNode node)
        {
            if (node.left != null)
            {
                SetTotals(node.left);
                node.val += node.left.val;
            }

            if (node.right != null)
            {
                SetTotals(node.right);
                node.val += node.right.val;
            }
        }

        private ulong GetHighestProduct(TreeNode node, int totalSum, ulong currentTotal = 0)
        {
            if (node.left != null)
            {
                ulong diff = (ulong)(totalSum - node.left.val);
                ulong newTotal = (ulong)node.left.val * diff;
                if (newTotal > currentTotal)
                {
                    currentTotal = newTotal;
                }

                newTotal = GetHighestProduct(node.left, totalSum, currentTotal);
                if (newTotal > currentTotal)
                {
                    currentTotal = newTotal;
                }
            }

            if (node.right != null)
            {
                ulong diff = (ulong)(totalSum - node.right.val);
                ulong newTotal = (ulong)node.right.val * diff;
                if (newTotal > currentTotal)
                {
                    currentTotal = newTotal;
                }

                newTotal = GetHighestProduct(node.right, totalSum, currentTotal);
                if (newTotal > currentTotal)
                {
                    currentTotal = newTotal;
                }
            }

            return currentTotal;
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
                    left = new TreeNode
                    {
                        val = 6
                    }
                },
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
                }
            };

            var treeTwo = new TreeNode
            {
                val = 1,
                right = new TreeNode
                {
                    val = 2,
                    left = new TreeNode
                    {
                        val = 3
                    },
                    right = new TreeNode
                    {
                        val = 4,
                        left = new TreeNode
                        {
                            val = 5
                        },
                        right = new TreeNode
                        {
                            val = 6
                        }
                    }
                }
            };

            var treeThree = new TreeNode
            {
                val = 1,
                left = new TreeNode
                {
                    val = 1
                }
            };

            Console.WriteLine(solution.MaxProduct(treeOne));
            Console.WriteLine(solution.MaxProduct(treeTwo));
            Console.WriteLine(solution.MaxProduct(treeThree));

            Console.ReadKey();
        }
    }
}
