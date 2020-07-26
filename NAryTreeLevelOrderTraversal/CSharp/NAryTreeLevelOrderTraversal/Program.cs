using System;
using System.Collections.Generic;

namespace NAryTreeLevelOrderTraversal
{
    public class Node
    {
        public int val;
        public IList<Node> children;

        public Node() { }

        public Node(int _val)
        {
            val = _val;
        }

        public Node(int _val, IList<Node> _children)
        {
            val = _val;
            children = _children;
        }
    }


    public class Solution
    {
        public IList<IList<int>> LevelOrder(Node root)
        {
            var result = new List<IList<int>>();

            if (root == null)
            {
                return result;
            }

            result.Add(new List<int> { root.val });

            var children = root.children;

            while (children != null && children.Count > 0)
            {
                var newChildren = new List<Node>();
                var newList = new List<int>();

                foreach (var child in children)
                {
                    newList.Add(child.val);

                    if (child.children != null && child.children.Count > 0)
                    {
                        newChildren.AddRange(child.children);
                    }
                }

                children = newChildren;
                result.Add(newList);
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var nodeOne = new Node(1)
            {
                children = new List<Node>
                {
                    new Node(3)
                    {
                        children = new List<Node>
                        {
                            new Node(5),
                            new Node(6)
                        }
                    },
                    new Node(2),
                    new Node(4)
                }
            };

            var nodeTwo = new Node(1)
            {
                children = new List<Node>
                {
                    new Node(2),
                    new Node(3)
                    {
                        children = new List<Node>
                        {
                            new Node(6),
                            new Node(7)
                            {
                                children = new List<Node>
                                {
                                    new Node(11)
                                    {
                                        children = new List<Node>
                                        {
                                            new Node(14)
                                        }
                                    }
                                }
                            }
                        }
                    },
                    new Node(4)
                    {
                        children = new List<Node>
                        {
                            new Node(8)
                            {
                                children = new List<Node>
                                {
                                    new Node(12)
                                }
                            }
                        }
                    },
                    new Node(5)
                    {
                        children = new List<Node>
                        {
                            new Node(9)
                            {
                                children = new List<Node>
                                {
                                    new Node(13)
                                }

                            },
                            new Node(10)
                        }
                    }
                }
            };

            var resultOne = solution.LevelOrder(nodeOne);
            var resultTwo = solution.LevelOrder(nodeTwo);

            Console.ReadKey();
        }
    }
}
