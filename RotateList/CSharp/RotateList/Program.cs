using System;
using System.Collections.Generic;

namespace RotateList
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }

    public class Solution
    {
        public ListNode RotateRight(ListNode head, int k)
        {
            if (head == null || head.next == null || k == 0)
            {
                return head;
            }

            var nodeStack = new Stack<ListNode>();
            nodeStack.Push(head);
            var next = head.next;
            while (next != null)
            {
                nodeStack.Push(next);
                next = next.next;
            }

            if (nodeStack.Count <= k)
            {
                k %= nodeStack.Count;
            }

            if (nodeStack.Count == k || k == 0)
            {
                return head;
            }

            var last = nodeStack.Peek();
            last.next = head;

            ListNode newHead = null;
            for (int i = 0; i < k; i++)
            {
                newHead = nodeStack.Pop();
            }

            head = newHead;
            var newEnd = nodeStack.Pop();
            newEnd.next = null;

            return head;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.RotateRight(
                new ListNode
                {
                    val = 1,
                    next = new ListNode
                    {
                        val = 2,
                        next = new ListNode
                        {
                            val = 3,
                            next = new ListNode
                            {
                                val = 4,
                                next = new ListNode
                                {
                                    val = 5,
                                }
                            }
                        }
                    }
                }, 2);

            var result2 = solution.RotateRight(
                new ListNode
                {
                    val = 0,
                    next = new ListNode
                    {
                        val = 1,
                        next = new ListNode
                        {
                            val = 2,
                        }
                    }
                }, 4);

            var result3 = solution.RotateRight(
                new ListNode { val = 1 }, 1);

            var result4 = solution.RotateRight(
                new ListNode
                {
                    val = 1,
                    next = new ListNode
                    {
                        val = 2
                    }
                }, 2);

            Console.ReadKey();
        }
    }
}
