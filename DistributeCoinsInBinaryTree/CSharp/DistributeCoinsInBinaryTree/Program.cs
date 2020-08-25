using System;

namespace DistributeCoinsInBinaryTree
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

    public class Result
    {
        public int CoinsNeeded { get; set; }
        public int CoinsHave { get; set; }
        public int TotalMoves { get; set; }
    }

    public class Solution
    {
        public int DistributeCoins(TreeNode root)
        {
            if (root == null)
            {
                return 0;
            }

            var result = GetResult(root);

            return result.TotalMoves;
        }

        private Result GetResult(TreeNode node)
        {
            var result = new Result();

            if (node.left != null)
            {
                var leftResult = GetResult(node.left);
                result.TotalMoves = leftResult.TotalMoves;
                result.CoinsNeeded = leftResult.CoinsNeeded;
                result.CoinsHave = leftResult.CoinsHave;
            }

            if (node.right != null)
            {
                var rightResult = GetResult(node.right);
                result.TotalMoves += rightResult.TotalMoves;
                if (rightResult.CoinsHave > 0)
                {
                    if (result.CoinsHave > 0)
                    {
                        result.CoinsHave += rightResult.CoinsHave;
                    }
                    else if (result.CoinsNeeded >= rightResult.CoinsHave)
                    {
                        result.CoinsNeeded -= rightResult.CoinsHave;
                    }
                    else
                    {
                        result.CoinsHave = rightResult.CoinsHave - result.CoinsNeeded;
                        result.CoinsNeeded = 0;
                    }
                }

                if (rightResult.CoinsNeeded > 0)
                {
                    if (result.CoinsNeeded > 0)
                    {
                        result.CoinsNeeded += rightResult.CoinsNeeded;
                    }
                    else if (result.CoinsHave >= rightResult.CoinsNeeded)
                    {
                        result.CoinsHave -= rightResult.CoinsNeeded;
                    }
                    else
                    {
                        result.CoinsNeeded = rightResult.CoinsNeeded - result.CoinsHave;
                        result.CoinsHave = 0;
                    }
                }
            }

            if (node.val == 0)
            {
                if (result.CoinsHave >= 1)
                {
                    result.CoinsHave--;
                }
                else
                {
                    result.CoinsNeeded++;
                }
            }
            else if (node.val > 1)
            {
                var extraCoins = node.val - 1;
                if (extraCoins >= result.CoinsNeeded)
                {
                    result.CoinsHave += extraCoins - result.CoinsNeeded;
                    result.CoinsNeeded = 0;
                }
                else
                {
                    result.CoinsNeeded -= extraCoins;
                }
            }

            result.TotalMoves += 1 * Math.Max(result.CoinsHave, result.CoinsNeeded);

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
                left = new TreeNode(),
                right = new TreeNode()
            };

            var treeTwo = new TreeNode
            {
                val = 0,
                left = new TreeNode(3),
                right = new TreeNode()
            };

            var treeThree = new TreeNode
            {
                val = 1,
                left = new TreeNode(),
                right = new TreeNode(2)
            };

            var treeFour = new TreeNode
            {
                val = 1,
                right = new TreeNode(),
                left = new TreeNode
                {
                    right = new TreeNode(3)
                }
            };

            var treeFive = new TreeNode
            {
                left = new TreeNode
                {
                    right = new TreeNode
                    {
                        right = new TreeNode()
                    },
                    left = new TreeNode
                    {
                        left = new TreeNode
                        {
                            val = 4,
                            left = new TreeNode(3)
                        }
                    }
                }
            };

            Console.WriteLine(solution.DistributeCoins(treeOne));
            Console.WriteLine(solution.DistributeCoins(treeTwo));
            Console.WriteLine(solution.DistributeCoins(treeThree));
            Console.WriteLine(solution.DistributeCoins(treeFour));
            Console.WriteLine(solution.DistributeCoins(treeFive));

            Console.ReadKey();
        }
    }
}
