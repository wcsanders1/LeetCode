using System;

namespace RemoveDuplicatesFromSortedList
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
        public ListNode DeleteDuplicates(ListNode head)
        {
            if (head == null)
            {
                return null;
            }

            var currentNode = head.next;
            var previousNode = head;

            while (currentNode != null)
            {
                if (currentNode.val == previousNode.val)
                {
                    previousNode.next = currentNode.next;
                }
                else
                {
                    previousNode = currentNode;
                }

                currentNode = currentNode.next;
            }

            return head;
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
                    val = 1,
                    next = new ListNode
                    {
                        val = 2,
                    }
                }
            };

            var listTwo = new ListNode
            {
                val = 1,
                next = new ListNode
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
                                val = 3
                            }
                        }
                    }
                }
            };

            var resultOne = solution.DeleteDuplicates(listOne);
            var resultTwo = solution.DeleteDuplicates(listTwo);

            Console.ReadKey();
        }
    }
}
