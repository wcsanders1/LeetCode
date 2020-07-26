using System;

namespace ValidateBinarySearchTree
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
        public bool IsValidBST(TreeNode root)
        {
            if (root == null)
            {
                return true;
            }

            return IsValidBST(root, long.MinValue, long.MaxValue);
        }

        private bool IsValidBST(TreeNode node, long lowestLeft, long highestRight)
        {
            if (node.left != null)
            {
                if (node.left.val >= node.val || node.left.val <= lowestLeft)
                {
                    return false;
                }

                if (!IsValidBST(node.left, lowestLeft, Math.Min(highestRight, node.val)))
                {
                    return false;
                }
            }

            if (node.right != null)
            {
                if (node.right.val <= node.val || node.right.val >= highestRight)
                {
                    return false;
                }

                if (!IsValidBST(node.right, Math.Max(lowestLeft, node.val), highestRight))
                {
                    return false;
                }
            }

            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var treeOne = new TreeNode
            {
                val = 2,
                left = new TreeNode
                {
                    val = 1
                },
                right = new TreeNode
                {
                    val = 3
                }
            };

            var treeTwo = new TreeNode
            {
                val = 5,
                left = new TreeNode
                {
                    val = 1
                },
                right = new TreeNode
                {
                    val = 4,
                    left = new TreeNode
                    {
                        val = 3
                    },
                    right = new TreeNode
                    {
                        val = 6
                    }
                }
            };

            var treeThree = new TreeNode
            {
                val = 10,
                left = new TreeNode
                {
                    val = 5,
                },
                right = new TreeNode
                {
                    val = 15,
                    left = new TreeNode
                    {
                        val = 6
                    },
                    right = new TreeNode
                    {
                        val = 20
                    }
                }
            };

            var treeFour = new TreeNode
            {
                val = -2147483648,
                right = new TreeNode
                {
                    val = 2147483647
                }
            };

            var treeFive = new TreeNode
            {
                val = 3,
                left = new TreeNode
                {
                    val = 1,
                    left = new TreeNode
                    {
                        val = 0
                    },
                    right = new TreeNode
                    {
                        val = 2,
                        right = new TreeNode
                        {
                            val = 3
                        }
                    }
                },
                right = new TreeNode
                {
                    val = 5,
                    left = new TreeNode
                    {
                        val = 4
                    },
                    right = new TreeNode
                    {
                        val = 6
                    }
                }
            };

            Console.WriteLine(solution.IsValidBST(treeOne));
            Console.WriteLine(solution.IsValidBST(treeTwo));
            Console.WriteLine(solution.IsValidBST(treeThree));
            Console.WriteLine(solution.IsValidBST(treeFour));
            Console.WriteLine(solution.IsValidBST(treeFive));

            Console.ReadKey();
        }
    }
}
