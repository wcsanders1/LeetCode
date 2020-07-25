using System;
using System.Collections.Generic;

namespace SymmetricTree
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
        public bool IsSymmetric(TreeNode root)
        {
            if (root == null)
            {
                return true;
            }

            return IsSymmetric(new List<TreeNode>
            {
                root.left,
                root.right
            });
        }

        private bool IsSymmetric(List<TreeNode> nodes)
        {
            var childNodesStart = new List<TreeNode>();
            var childNodesEnd = new Stack<TreeNode>();

            var start = 0;
            var end = nodes.Count - 1;
            var hasChildNodes = false;

            while (start < end)
            {
                var startNode = nodes[start++];
                var endNode = nodes[end--];

                if (startNode?.val != endNode?.val)
                {
                    return false;
                }

                if (startNode?.left != null || startNode?.right != null || endNode?.left != null || endNode?.right != null)
                {
                    hasChildNodes = true;
                }

                childNodesStart.Add(startNode?.left);
                childNodesStart.Add(startNode?.right);
                childNodesEnd.Push(endNode?.right);
                childNodesEnd.Push(endNode?.left);
            }

            if (hasChildNodes)
            {
                while(childNodesEnd.Count > 0)
                {
                    childNodesStart.Add(childNodesEnd.Pop());
                }

                return IsSymmetric(childNodesStart);
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
                val = 1,
                left = new TreeNode
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
                },
                right = new TreeNode
                {
                    val = 2,
                    left = new TreeNode
                    {
                        val = 4
                    },
                    right = new TreeNode
                    {
                        val = 3
                    }
                }
            };

            var treeTwo = new TreeNode
            {
                val = 1,
                left = new TreeNode
                {
                    val = 2,
                    right = new TreeNode
                    {
                        val = 3
                    }
                },
                right = new TreeNode
                {
                    val = 2,
                    right = new TreeNode
                    {
                        val = 3
                    }
                }
            };

            Console.WriteLine(solution.IsSymmetric(treeOne));
            Console.WriteLine(solution.IsSymmetric(treeTwo));

            Console.ReadKey();
        }
    }
}
