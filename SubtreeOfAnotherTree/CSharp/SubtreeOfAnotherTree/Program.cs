using System;

namespace SubtreeOfAnotherTree
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
        public bool IsSubtree(TreeNode s, TreeNode t)
        {
            return Match(s, t);
        }

        private bool Match(TreeNode s, TreeNode t)
        {
            if (s == null || t == null)
            {
                return false;
            }

            if (s.val == t.val && AreEqual(s, t))
            {
                return true;
            }

            return Match(s.left, t) || Match(s.right, t);
        }

        private bool AreEqual(TreeNode s, TreeNode t)
        {
            if (s?.val != t?.val)
            {
                return false;
            }

            bool leftIsEqual;
            if (s?.left != null || t?.left != null)
            {
                leftIsEqual = AreEqual(s?.left, t?.left);
            }
            else
            {
                leftIsEqual = true;
            }

            bool rightIsEqual;
            if (s?.right != null || t?.right != null)
            {
                rightIsEqual = AreEqual(s?.right, t?.right);
            }
            else
            {
                rightIsEqual = true;
            }

            return leftIsEqual && rightIsEqual;
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
                left = new TreeNode
                {
                    val = 4,
                    left = new TreeNode(1),
                    right = new TreeNode(2)
                },
                right = new TreeNode(5)
            };

            var subOne = new TreeNode
            {
                val = 4,
                left = new TreeNode(1),
                right = new TreeNode(2)
            };

            var treeTwo = new TreeNode
            {
                val = 3,
                left = new TreeNode
                {
                    val = 4,
                    left = new TreeNode(1),
                    right = new TreeNode
                    {
                        val = 2,
                        left = new TreeNode(0)
                    }
                },
                right = new TreeNode(5)
            };

            var treeThree = new TreeNode
            {
                val = 1,
                left = new TreeNode(1)
            };

            var subTwo = new TreeNode(1);

            Console.WriteLine(solution.IsSubtree(treeOne, subOne));
            Console.WriteLine(solution.IsSubtree(treeTwo, subOne));
            Console.WriteLine(solution.IsSubtree(treeThree, subTwo));

            Console.ReadKey();
        }
    }
}
