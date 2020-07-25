using System;

namespace BinaryTreeMaximumSumPath
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
        private int MaxPath = int.MinValue;

        public int MaxPathSum(TreeNode root)
        {
            if (root == null)
            {
                return 0;
            }

            MaxPath = int.MinValue;

            GetMaxPathSum(root);

            return MaxPath;
        }

        private int GetMaxPathSum(TreeNode node)
        {
            if (node == null)
            {
                return 0;
            }

            var highestLeft = Math.Max(0, GetMaxPathSum(node.left));
            var highestRight = Math.Max(0, GetMaxPathSum(node.right));
            MaxPath = Math.Max(MaxPath, highestLeft + highestRight + node.val);

            return Math.Max(highestLeft, highestRight) + node.val;
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
                left = new TreeNode
                {
                    val = 2
                },
                right = new TreeNode
                {
                    val = 3
                }
            };

            var treeTwo = new TreeNode
            {
                val = -10,
                left = new TreeNode
                {
                    val = 9
                },
                right = new TreeNode
                {
                    val = 20,
                    left = new TreeNode
                    {
                        val = 15
                    },
                    right = new TreeNode
                    {
                        val = 7
                    }
                }
            };

            var treeThree = new TreeNode
            {
                val = -3
            };

            var treeFour = new TreeNode
            {
                val = 2,
                left = new TreeNode
                {
                    val = -1
                }
            };

            var treeFive = new TreeNode
            {
                val = -10,
                left = new TreeNode
                {
                    val = -9
                },
                right = new TreeNode
                {
                    val = -20,
                    left = new TreeNode
                    {
                        val = -15
                    },
                    right = new TreeNode
                    {
                        val = -7
                    }
                }
            };

            var treeSix = new TreeNode
            {
                val = 1,
                left = new TreeNode
                {
                    val = -2
                },
                right = new TreeNode
                {
                    val = 3
                }
            };

            Console.WriteLine(solution.MaxPathSum(treeOne));
            Console.WriteLine(solution.MaxPathSum(treeTwo));
            Console.WriteLine(solution.MaxPathSum(treeThree));
            Console.WriteLine(solution.MaxPathSum(treeFour));
            Console.WriteLine(solution.MaxPathSum(treeFive));
            Console.WriteLine(solution.MaxPathSum(treeSix));

            Console.ReadKey();
        }
    }
}
