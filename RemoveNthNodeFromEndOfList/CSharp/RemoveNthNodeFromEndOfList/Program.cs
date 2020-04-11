using System;

namespace RemoveNthNodeFromEndOfList
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

    public class Solution
    {
        public ListNode RemoveNthFromEnd(ListNode head, int n)
        {
            var result = RemoveNthFromRear(head, null, n);

            if (result == -1)
            {
                return head.next;
            }

            return head;
        }

        private int RemoveNthFromRear(ListNode head, ListNode previous, int n)
        {
            if (head == null)
            {
                return 1;
            }

            var currentIndexFromRear = RemoveNthFromRear(head.next, head, n);

            if (currentIndexFromRear == n)
            {
                if (previous == null)
                {
                    return -1;
                }
                previous.next = head.next;
            }

            return ++currentIndexFromRear;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var testList1 = new ListNode(1)
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
            }
;
            var result1 = solution.RemoveNthFromEnd(testList1, 2);

            Console.ReadKey();
        }
    }
}
