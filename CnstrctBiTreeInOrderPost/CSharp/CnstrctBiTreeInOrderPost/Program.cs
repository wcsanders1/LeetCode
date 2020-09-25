using System;
using System.Collections.Generic;

namespace CnstrctBiTreeInOrderPost
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
        public TreeNode BuildTree(int[] inorder, int[] postorder)
        {
            if (inorder == null || inorder.Length == 0)
            {
                return null;
            }

            var postorderIndex = postorder.Length - 1;
            var inorderIndex = inorder.Length - 1;

            var stack = new Stack<TreeNode>();
            TreeNode previous = null;
            var root = new TreeNode(postorder[postorderIndex--]);
            stack.Push(root);

            while (postorderIndex >= 0)
            {
                while (stack.Count > 0 && stack.Peek().val == inorder[inorderIndex])
                {
                    previous = stack.Pop();
                    inorderIndex--;
                }

                var newNode = new TreeNode(postorder[postorderIndex]);
                if (previous != null)
                {
                    previous.left = newNode;
                }
                else if (stack.Count > 0)
                {
                    var currentTop = stack.Peek();
                    currentTop.right = newNode;
                }

                stack.Push(newNode);
                previous = null;
                postorderIndex--;
            }

            return root;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            //var resultOne = solution.BuildTree(
            //    new int[] { 9, 3, 15, 20, 7 },
            //    new int[] { 9, 15, 7, 20, 3 });

            var resultTwo = solution.BuildTree(
                new int[] { 6, 5, 10, 8, 12, 3, 1, 2, 7, 4, 9 },
                new int[] { 6, 10, 12, 8, 5, 1, 7, 9, 4, 2, 3 });

            Console.ReadKey();
        }
    }
}
