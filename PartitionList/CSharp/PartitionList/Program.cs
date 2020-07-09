using System;

namespace PartitionList
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
        public ListNode Partition(ListNode head, int x)
        {
            if (head?.next == null)
            {
                return head;
            }

            ListNode startHead = null;
            ListNode endHead = null;
            ListNode currentStart = null;
            ListNode currentEnd = null;

            var currentNode = head;

            while (currentNode != null)
            {
                var next = currentNode.next;
                if (currentNode.val < x)
                {
                    if (startHead == null)
                    {
                        startHead = currentNode;
                        currentStart = startHead;
                    }
                    else
                    {
                        currentStart.next = currentNode;
                        currentStart = currentNode;
                    }
                    currentStart.next = null;
                }
                else
                {
                    if (endHead == null)
                    {
                        endHead = currentNode;
                        currentEnd = endHead;
                    }
                    else
                    {
                        currentEnd.next = currentNode;
                        currentEnd = currentNode;
                    }
                    currentEnd.next = null;
                }

                currentNode = next;
            }

            if (startHead == null)
            {
                return endHead;
            }

            if (endHead == null)
            {
                return startHead;
            }

            currentStart.next = endHead;

            return startHead;
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
                    val = 4,
                    next = new ListNode
                    {
                        val = 3,
                        next = new ListNode
                        {
                            val = 2,
                            next = new ListNode
                            {
                                val = 5,
                                next = new ListNode
                                {
                                    val = 2
                                }
                            }
                        }
                    }
                }
            };

            var resultOne = solution.Partition(listOne, 3);

            Console.ReadKey();
        }
    }
}
