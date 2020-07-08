using System;

namespace RemoveDuplicatesFromSortedListII
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
            ListNode previousNode = null;
            var currentNode = head;

            while(currentNode != null)
            {
                if (currentNode.next == null)
                {
                    return head;
                }

                var nextNode = currentNode.next;

                if (currentNode.val != nextNode.val)
                {
                    previousNode = currentNode;
                    currentNode = nextNode;
                    continue;
                }

                while (currentNode.val == nextNode.val)
                {
                    nextNode = nextNode.next;
                    if (nextNode == null)
                    {
                        break;
                    }
                }

                if (previousNode == null)
                {
                    head = nextNode;
                }
                else
                {
                    previousNode.next = nextNode;
                }

                currentNode = nextNode;
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
                    val = 2,
                    next = new ListNode
                    {
                        val = 3,
                        next = new ListNode
                        {
                            val = 3,
                            next = new ListNode
                            {
                                val = 4,
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
                    }
                }
            };

            var listTwo = new ListNode
            { 
                val = 1,
                next = new ListNode
                {
                    val = 1
                }
            };


            var resultOne = solution.DeleteDuplicates(listOne);
            var resultTwo = solution.DeleteDuplicates(listTwo);

            Console.ReadKey();
        }
    }
}
