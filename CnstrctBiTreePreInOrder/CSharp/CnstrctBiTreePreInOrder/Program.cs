using System;
using System.Linq;

namespace CnstrctBiTreePreInOrder
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
        public TreeNode BuildTree(int[] preorder, int[] inorder)
        {
            if (preorder.Length == 0 || inorder.Length == 0)
            {
                return null;
            }

            var root = new TreeNode(preorder[0]);

            var inIndex = Array.IndexOf(inorder, preorder[0]);

            root.left = BuildTree(preorder.Skip(1).Take(inIndex).ToArray(), inorder.Take(inIndex).ToArray());
            root.right = BuildTree(preorder.Skip(inIndex + 1).ToArray(), inorder.Skip(inIndex + 1).ToArray());

            return root;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var resultOne = solution.BuildTree(
                new int[] { 3, 5, 6, 8, 10, 12, 2, 4, 7, 9 },
                new int[] { 6, 5, 10, 8, 12, 3, 2, 7, 4, 9 });

            var resultTwo = solution.BuildTree(
                new int[] { 3, 9, 20, 15, 7 },
                new int[] { 9, 3, 15, 20, 7 });

            Console.ReadKey();
        }
    }
}
