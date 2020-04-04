using System;

namespace AddTwoNumbers
{
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

    public class Solution
    {
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            var currentNodeOne = l1;
            var currentNodeTwo = l2;
            var carry = false;
            ListNode firstNode = null;
            ListNode lastNode = null;
            while (currentNodeOne != null || currentNodeTwo != null || carry)
            {
                var sum = carry ? 1 : 0;
                if (currentNodeOne != null)
                {
                    sum += currentNodeOne.val;
                }
                
                if (currentNodeTwo != null)
                {
                    sum += currentNodeTwo.val;
                }

                if (firstNode == null)
                {
                    firstNode = new ListNode(sum % 10);
                    lastNode = firstNode;
                }
                else
                {
                    var newNode = new ListNode(sum % 10);
                    lastNode.next = newNode;
                    lastNode = newNode;
                }
                carry = sum >= 10;

                if (currentNodeOne != null)
                {
                    currentNodeOne = currentNodeOne.next;
                }

                if (currentNodeTwo != null)
                {
                    currentNodeTwo = currentNodeTwo.next;
                }
            }

            return firstNode;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var one = new ListNode(1)
            {
                next = new ListNode(1)
                {
                    next = new ListNode(1)
                    {
                        next = new ListNode(1)
                        {
                            next = new ListNode(1)
                            {
                                next = new ListNode(1)
                                {
                                    next = new ListNode(1)
                                    {
                                        next = new ListNode(1)
                                        {
                                            next = new ListNode(1)
                                            {
                                                next = new ListNode(1)
                                                {
                                                    next = new ListNode(1)
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            };

            var two = new ListNode(1)
            {
                next = new ListNode(1)
                {
                    next = new ListNode(1)
                    {
                        next = new ListNode(1)
                        {
                            next = new ListNode(1)
                            {
                                next = new ListNode(1)
                                {
                                    next = new ListNode(1)
                                    {
                                        next = new ListNode(1)
                                        {
                                            next = new ListNode(1)
                                            {
                                                next = new ListNode(1)
                                                {
                                                    next = new ListNode(1)
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            };

            var solution = new Solution();
            var result = solution.AddTwoNumbers(one, two);

            Console.ReadKey();
        }
    }
}
