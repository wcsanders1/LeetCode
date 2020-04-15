using System;
using System.Collections.Generic;

namespace NextPermutation
{
	public class Solution
	{
		public void NextPermutation(int[] nums)
		{
			var numsReversed = new Queue<int>();
			numsReversed.Enqueue(nums[^1]);
			var swapPlace = -1;

			for (var i = nums.Length - 1; i > 0; i--)
			{
				numsReversed.Enqueue(nums[i - 1]);
				if (nums[i - 1] < nums[i])
				{
					swapPlace = i - 1;
					break;
				}
			}

			if (swapPlace == -1)
			{
				for (var i = 0; i < nums.Length; i++)
				{
					nums[i] = numsReversed.Dequeue();
				}
				return;
			}

			var swapWithIndex = swapPlace + 1;
			for (var i = swapWithIndex + 1; i < nums.Length; i++)
			{
				if (nums[i] > nums[swapPlace])
				{
					swapWithIndex = i;
				}
			}

			var swapNumber1 = nums[swapPlace];
			var swapNumber2 = nums[swapWithIndex];

			nums[swapPlace] = swapNumber2;
			nums[swapWithIndex] = swapNumber1;

			var newOrder = new Stack<int>();
			for (var i = swapPlace + 1; i < nums.Length; i++)
			{
				newOrder.Push(nums[i]);
			}

			for (var i = swapPlace + 1; i < nums.Length; i++)
			{
				nums[i] = newOrder.Pop();
			}
		}
	}

	class Program
    {
        static void Main(string[] args)
        {
			var solution = new Solution();

			var arr1 = new int[] { 1, 2, 3 };
			var arr2 = new int[] { 3, 2, 1 };
			var arr3 = new int[] { 1, 1, 5 };
			var arr4 = new int[] { 1, 1, 3, 2, 1 };
			var arr5 = new int[] { 1 };

			solution.NextPermutation(arr1);
			solution.NextPermutation(arr2);
			solution.NextPermutation(arr3);
			solution.NextPermutation(arr4);
			solution.NextPermutation(arr5);

			Console.ReadKey();
        }
    }
}
