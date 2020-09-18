using System;

namespace LinkedListCycleII
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x)
        {
            val = x;
            next = null;
        }
    }

    public class Solution
    {
        public ListNode DetectCycle(ListNode head)
        {
            if (head?.next == null)
            {
                return null;
            }

            ListNode slow = head;
            ListNode fast = head;

            while (slow == head || slow != fast)
            {
                if (fast?.next?.next == null)
                {
                    return null;
                }

                slow = slow.next;
                fast = fast.next.next;

                if (fast == head)
                {
                    return head;
                }
            }

            slow = head;

            while (slow != fast)
            {
                slow = slow.next;
                fast = fast.next;
            }

            return slow;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var linkThree = new ListNode(3);
            var linkTwo = new ListNode(2);
            var linkZero = new ListNode(0);
            var linkNFour = new ListNode(-4);

            linkThree.next = linkTwo;
            linkTwo.next = linkZero;
            linkZero.next = linkNFour;
            linkNFour.next = linkTwo;

            var resultOne = solution.DetectCycle(linkThree);

            var linkOne = new ListNode(1);

            linkOne.next = linkTwo;
            linkTwo.next = linkOne;

            var resultTwo = solution.DetectCycle(linkOne);

            linkOne.next = null;

            var resultThree = solution.DetectCycle(linkOne);

            Console.ReadKey();
        }
    }
}
