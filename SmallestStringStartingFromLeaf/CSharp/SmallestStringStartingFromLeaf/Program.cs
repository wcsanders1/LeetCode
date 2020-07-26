using System;
using System.Collections.Generic;

namespace SmallestStringStartingFromLeaf
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
        private List<int> Result;

        public string SmallestFromLeaf(TreeNode root)
        {
            Result = new List<int>();

            if (root == null)
            {
                return string.Empty;
            }

            SetResult(root);

            var chars = new char[Result.Count];
            var index = 0;
            for (var i = Result.Count - 1; i >= 0 ; i--)
            {
                chars[index++] = (char)(Result[i] + 97);
            }

            return new string(chars);
        }

        public void SetResult(TreeNode node, List<int> currentNums = null, int currentSum = 0)
        {
            if (currentNums == null)
            {
                currentNums = new List<int>();
            }

            currentNums.Add(node.val);
            currentSum += node.val;

            if (node.left == null && node.right == null)
            {
                SetLeast(currentNums);

                return;
            }

            if (node.left != null)
            {
                SetResult(node.left, new List<int>(currentNums), currentSum);
            }

            if (node.right != null)
            {
                SetResult(node.right, new List<int>(currentNums), currentSum);
            }
        }

        private void SetLeast(List<int> nums)
        {
            if (Result.Count == 0)
            {
                Result = nums;

                return;
            }

            var index = nums.Count - 1;
            for (int i = Result.Count - 1; i >= 0; i--)
            {
                if (index < 0)
                {
                    Result = nums;

                    return;
                }

                if (nums[index] < Result[i])
                {
                    Result = nums;

                    return;
                }

                if (nums[index] > Result[i])
                {
                    return;
                }

                index--;
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
                val = 0,
                left = new TreeNode
                {
                    val = 1,
                    left = new TreeNode
                    {
                        val = 3
                    },
                    right = new TreeNode
                    {
                        val = 4
                    }
                },
                right = new TreeNode
                {
                    val = 2,
                    left = new TreeNode
                    {
                        val = 3
                    },
                    right = new TreeNode
                    {
                        val = 4
                    }
                }
            };

            var treeTwo = new TreeNode
            {
                val = 25,
                left = new TreeNode
                {
                    val = 1,
                    left = new TreeNode
                    {
                        val = 1
                    },
                    right = new TreeNode
                    {
                        val = 3
                    }
                },
                right = new TreeNode
                {
                    val = 3,
                    left = new TreeNode
                    {
                        val = 0
                    },
                    right = new TreeNode
                    {
                        val = 2
                    }
                }
            };

            var treeThree = new TreeNode
            {
                val = 2,
                left = new TreeNode
                {
                    val = 2,
                    right = new TreeNode
                    {
                        val = 1,
                        left = new TreeNode
                        {
                            val = 0
                        }
                    }
                },
                right = new TreeNode
                {
                    val = 1,
                    left = new TreeNode
                    {
                        val = 0
                    }
                }
            };

            var treeFour = new TreeNode
            {
                val = 4,
                left = new TreeNode
                {
                    val = 0,
                    left = new TreeNode
                    {
                        val = 1
                    }
                },
                right = new TreeNode
                {
                    val = 1
                }
            };

            Console.WriteLine(solution.SmallestFromLeaf(treeOne));
            Console.WriteLine(solution.SmallestFromLeaf(treeTwo));
            Console.WriteLine(solution.SmallestFromLeaf(treeThree));
            Console.WriteLine(solution.SmallestFromLeaf(treeFour));

            Console.ReadKey();
        }
    }
}
