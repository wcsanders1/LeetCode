using System;
using System.Linq;

namespace MergeKSortedLists
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

    public class Solution
    {
        public ListNode MergeKLists(ListNode[] lists)
        {
            ListNode result = null;
            ListNode currentNode = null;

            if (!lists.Any(list => list != null))
            {
                return result;
            }

            while (true)
            {
                ListNode nextNode = null;

                var index = 0;
                var indexOfLowest = 0;
                foreach (var list in lists)
                {
                    if (list == null)
                    {
                        index++;
                        continue;
                    }
                    
                    if (nextNode == null || nextNode.val > list.val)
                    {
                        indexOfLowest = index;
                        nextNode = list;
                    }
                    index++;
                }

                if (nextNode == null)
                {
                    return result;
                }

                if (result == null)
                {
                    result = nextNode;
                }
                else
                {
                    currentNode.next = nextNode;
                }
                currentNode = nextNode;
                lists[indexOfLowest] = nextNode.next;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var node1 = new ListNode(1)
            {
                next = new ListNode(4)
                {
                    next = new ListNode(5)
                }
            };

            var node2 = new ListNode(1)
            {
                next = new ListNode(3)
                {
                    next = new ListNode(4)
                }
            };

            var node3 = new ListNode(2)
            {
                next = new ListNode(6)
            };

            var result1 = solution.MergeKLists(new ListNode[] { node1, node2, node3 });

            Console.ReadKey();
        }
    }
}
