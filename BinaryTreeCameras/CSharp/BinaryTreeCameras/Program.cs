using System;

namespace BinaryTreeCameras
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
        public int MinCameraCover(TreeNode root)
        {
            if (root == null)
            {
                return 0;
            }

            if (root.left == null && root.right == null)
            {
                return 1;
            }

            return GetCameraCount(root);
        }

        private int GetCameraCount(TreeNode node, int cameras = 0, int depth = 0)
        {
            if (node.left == null && node.right == null)
            {
                return cameras;
            }

            if (node.left != null)
            {
                cameras = GetCameraCount(node.left, cameras, depth + 1);
            }

            if (node.right != null)
            {
                cameras = GetCameraCount(node.right, cameras, depth + 1);
            }

            if ((node.left?.val ?? 1) == 0 || (node.right?.val ?? 1) == 0)
            {
                node.val = 2;
                cameras++;
            }
            else if ((node.left?.val ?? 1) == 2 || (node.right?.val ?? 1) == 2)
            {
                node.val = 1;
            }

            if (depth == 0 && node.val < 2 && (node.left?.val ?? 1) < 2 && (node.right?.val ?? 1) < 2)
            {
                cameras++;
            }

            return cameras;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var treeOne = new TreeNode
            {
                left = new TreeNode
                {
                    left = new TreeNode(),
                    right = new TreeNode()
                }

            };

            var treeTwo = new TreeNode
            {
                left = new TreeNode
                {
                    left = new TreeNode
                    {
                        left = new TreeNode
                        {
                            right = new TreeNode()
                        }
                    }
                }
            };

            var treeThree = new TreeNode
            {
                left = new TreeNode
                {
                    left = new TreeNode
                    {
                        left = new TreeNode(),
                        right = new TreeNode()
                    },
                    right = new TreeNode()
                },
                right = new TreeNode
                {
                    right = new TreeNode
                    {
                        left = new TreeNode
                        {
                            left = new TreeNode(),
                            right = new TreeNode()
                        }
                    }
                }
            };

            var treeFour = new TreeNode
            {
                left = new TreeNode
                {
                    left = new TreeNode
                    {
                        left = new TreeNode(),
                        right = new TreeNode()
                    },
                    right = new TreeNode
                    {
                        left = new TreeNode()
                    }
                },
                right = new TreeNode
                {
                    right = new TreeNode
                    {
                        left = new TreeNode
                        {
                            left = new TreeNode(),
                            right = new TreeNode()
                        }
                    }
                }
            };

            var treeFive = new TreeNode
            {
                left = new TreeNode
                {
                    right = new TreeNode
                    {
                        left = new TreeNode(),
                        right = new TreeNode
                        {
                            left = new TreeNode()
                        }
                    }
                }
            };

            var treeSix = new TreeNode
            {
                left = new TreeNode
                {
                    right = new TreeNode
                    {
                        left = new TreeNode
                        {
                            right = new TreeNode
                            {
                                left = new TreeNode()
                            }
                        }
                    }
                }
            };

            var treeSeven = new TreeNode
            {
                right = new TreeNode
                {
                    right = new TreeNode
                    {
                        right = new TreeNode()
                    }
                }
            };

            var treeEight = new TreeNode
            {
                right = new TreeNode
                {
                    left = new TreeNode(),
                    right = new TreeNode
                    {
                        right = new TreeNode()
                    }
                }

            };

            Console.WriteLine(solution.MinCameraCover(treeOne));
            Console.WriteLine(solution.MinCameraCover(treeTwo));
            Console.WriteLine(solution.MinCameraCover(treeThree));
            Console.WriteLine(solution.MinCameraCover(treeFour));
            Console.WriteLine(solution.MinCameraCover(treeFive));
            Console.WriteLine(solution.MinCameraCover(treeSix));
            Console.WriteLine(solution.MinCameraCover(treeSeven));
            Console.WriteLine(solution.MinCameraCover(treeEight));

            Console.ReadKey();
        }
    }
}
