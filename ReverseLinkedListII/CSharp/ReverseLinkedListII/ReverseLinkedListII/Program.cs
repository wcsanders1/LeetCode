using System;

namespace ReverseLinkedListII
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
        public ListNode ReverseBetween(ListNode head, int m, int n)
        {
            if (head?.next == null)
            {
                return head;
            }

            var current = head;
            var position = 0;
            ListNode prev = null;

            while (current != null)
            {
                if (++position < m)
                {
                    prev = current;
                    current = current.next;
                    continue;
                }

                var (reversedSection, first, last) = ReverseTo(current, position, n);
                reversedSection.next = last;

                if (prev != null)
                {
                    prev.next = first;
                }
                else
                {
                    head = first;
                }

                break;
            }

            return head;
        }

        private (ListNode Reversed, ListNode First, ListNode Last) ReverseTo(ListNode node, int currentPosition, int lastPosition)
        {
            if (currentPosition == lastPosition)
            {
                return (node, node, node.next);
            }

            var (reversedNode, first, last) = ReverseTo(node.next, currentPosition + 1, lastPosition);
            reversedNode.next = node;

            return (node, first, last);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var listOne = new ListNode
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
                                val = 5
                            }
                        }
                    }
                }
            };

            var resultOne = solution.ReverseBetween(listOne, 2, 4);

            Console.ReadKey();
        }
    }
}
