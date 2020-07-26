using System;
using System.Collections.Generic;

namespace SumRootToLeafNumbers
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
        public int SumNumbers(TreeNode root)
        {
            if (root == null)
            {
                return 0;
            }

            return GetSum(root);
        }

        private int GetSum(TreeNode node, Stack<int> digits = null)
        {
            if (digits == null)
            {
                digits = new Stack<int>();
            }

            digits.Push(node.val);

            if (node.left == null && node.right == null)
            {
                return GetNumberFromDigits(digits);
            }

            var result = 0;
            if (node.left != null)
            {
                result += GetSum(node.left, new Stack<int>(new Stack<int>(digits)));
            }

            if (node.right != null)
            {
                result += GetSum(node.right, new Stack<int>(new Stack<int>(digits)));
            }

            return result;
        }

        private int GetNumberFromDigits(Stack<int> digits)
        {
            var number = 0;
            var power = 0;
            while(digits.Count > 0)
            {
                number += digits.Pop() * (int)Math.Pow(10, power++);
            }

            return number;
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
                val = 4,
                left = new TreeNode
                {
                    val = 9,
                    right = new TreeNode
                    {
                        val = 5
                    },
                    left = new TreeNode
                    {
                        val = 1
                    }
                },
                right = new TreeNode
                {
                    val = 0
                }
            };

            Console.WriteLine(solution.SumNumbers(treeOne));
            Console.WriteLine(solution.SumNumbers(treeTwo));

            Console.ReadKey();
        }
    }
}
