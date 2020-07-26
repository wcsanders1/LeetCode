using System;
using System.Collections.Generic;

namespace NAryTreePreorderTraversal
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
        public IList<int> Preorder(Node root)
        {
            var result = new List<int>();

            if (root == null)
            {
                return result;
            }

            var nodes = new Stack<Node>();
            nodes.Push(root);

            while (nodes.Count > 0)
            {
                var node = nodes.Pop();

                result.Add(node.val);

                if (node.children == null || node.children.Count == 0)
                {
                    continue;
                }

                for (int i = node.children.Count - 1; i >= 0; i--)
                {
                    nodes.Push(node.children[i]);
                }
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

            var resultOne = solution.Preorder(nodeOne);
            var resultTwo = solution.Preorder(nodeTwo);

            Console.ReadKey();
        }
    }
}
