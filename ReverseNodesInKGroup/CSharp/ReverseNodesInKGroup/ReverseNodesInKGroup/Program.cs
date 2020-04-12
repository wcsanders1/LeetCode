using System;
using System.Collections.Generic;

namespace ReverseNodesInKGroup
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

    public class Solution
    {
        public ListNode ReverseKGroup(ListNode head, int k)
        {
            if (head == null || head.next == null)
            {
                return head;
            }

            var reversibleNodes = new Stack<ListNode>();
            var next = head;

            ListNode result = null;
            ListNode current = null;

            while (next != null)
            {
                var tempNext = next;
                for (var i = 0; i < k; i++)
                {
                    if (next == null)
                    {
                        reversibleNodes.Clear();
                        if (result == null)
                        {
                            return head;
                        }
                        else
                        {
                            current.next = tempNext;
                            return result;
                        }
                    }

                    reversibleNodes.Push(next);
                    next = next.next;
                }

                ListNode revseredListHead = null;
                ListNode revseredCurrent = null;
                ListNode lastNode = null;
                while(reversibleNodes.TryPop(out var newHead))
                {
                    lastNode = newHead;
                    if (revseredListHead == null)
                    {
                        revseredListHead = newHead;
                        revseredCurrent = newHead;
                    }
                    else
                    {
                        revseredCurrent.next = newHead;
                        revseredCurrent = newHead;
                        revseredCurrent.next = null;
                    }
                }

                if (result == null)
                {
                    if (revseredListHead == null)
                    {
                        return result;
                    }

                    result = revseredListHead;
                    current = lastNode;
                }
                else
                {
                    current.next = revseredListHead;
                    current = lastNode;
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

            var node1 = new ListNode(1)
            {
                next = new ListNode(2)
                {
                    next = new ListNode(3)
                    {
                        next = new ListNode(4)
                        {
                            next = new ListNode(5)
                        }
                    }
                }
            };

            var node2 = new ListNode(1)
            {
                next = new ListNode(2)
                {
                    next = new ListNode(3)
                    {
                        next = new ListNode(4)
                        {
                            next = new ListNode(5)
                        }
                    }
                }
            };

            var node3 = new ListNode(1)
            {
                next = new ListNode(2)
                {
                    next = new ListNode(3)
                    {
                        next = new ListNode(4)
                        {
                            next = new ListNode(5)
                        }
                    }
                }
            };

            var node4 = new ListNode(1)
            {
                next = new ListNode(2)
                {
                    next = new ListNode(3)
                    {
                        next = new ListNode(4)
                        {
                            next = new ListNode(5)
                        }
                    }
                }
            };

            var node5 = new ListNode(1)
            {
                next = new ListNode(2)
                {
                    next = new ListNode(3)
                    {
                        next = new ListNode(4)
                        {
                            next = new ListNode(5)
                        }
                    }
                }
            };

            var result1 = solution.ReverseKGroup(node1, 3);
            var result2 = solution.ReverseKGroup(node2, 2);
            var result3 = solution.ReverseKGroup(node3, 1);
            var result4 = solution.ReverseKGroup(node4, 5);
            var result5 = solution.ReverseKGroup(node5, 6);

            Console.ReadKey();
        }
    }
}
