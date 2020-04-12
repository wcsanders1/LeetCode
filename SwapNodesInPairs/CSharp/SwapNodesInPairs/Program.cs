using System;

namespace SwapNodesInPairs
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

    public class Solution
    {
        public ListNode SwapPairs(ListNode head)
        {
            if (head == null || head.next == null)
            {
                return head;
            }

            ListNode result = null;
            ListNode previous = null;
            ListNode next = head;

            while (next != null)
            {
                if (next.next == null)
                {
                    previous.next = next;
                    return result;
                }

                var newNext = next.next.next;
                
                var newFirst = next.next;
                var newSecond = next;
                newFirst.next = newSecond;


                if (result == null)
                {
                    result = newFirst;
                    previous = newSecond;
                }
                else
                {
                    previous.next = newFirst;
                    previous = newSecond;
                }

                previous.next = null;
                next = newNext;
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
                    }
                }
            };

            var node2 = new ListNode(1)
            {
                next = new ListNode(2)
                {
                    next = new ListNode(3)
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

            var result1 = solution.SwapPairs(node1);
            var result2 = solution.SwapPairs(node2);
            var result3 = solution.SwapPairs(node3);

            Console.ReadKey();
        }
    }
}
