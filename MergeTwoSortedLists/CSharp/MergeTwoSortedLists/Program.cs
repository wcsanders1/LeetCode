using System;

namespace MergeTwoSortedLists
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

    public class Solution
    {
        public ListNode MergeTwoLists(ListNode l1, ListNode l2)
        {
            ListNode newList = null;
            ListNode currentNode = null;

            var currentNode1 = l1;
            var currentNode2 = l2;

            if (l1 == null)
            {
                return l2;
            }

            if (l2 == null)
            {
                return l1;
            }

            while (currentNode1 != null || currentNode2 != null)
            {
                if (currentNode1 == null)
                {
                    currentNode.next = currentNode2;
                    return newList;
                }

                if (currentNode2 == null)
                {
                    currentNode.next = currentNode1;
                    return newList;
                }

                ListNode newNode;
                if (currentNode1.val < currentNode2.val)
                {
                    newNode = new ListNode(currentNode1.val);
                    currentNode1 = currentNode1.next;
                }
                else
                {
                    newNode = new ListNode(currentNode2.val);
                    currentNode2 = currentNode2.next;
                }

                if (newList == null)
                {
                    newList = newNode;
                    currentNode = newList;
                }
                else
                {
                    currentNode.next = newNode;
                    currentNode = newNode;
                }
            }

            return newList;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var list1 = new ListNode(1)
            {
                next = new ListNode(2)
                {
                    next = new ListNode(4)
                }
            };

            var list2 = new ListNode(1)
            {
                next = new ListNode(3)
                {
                    next = new ListNode(4)
                }
            };

            var result1 = solution.MergeTwoLists(list1, list2);

            Console.ReadKey();
        }
    }
}
