using System;

namespace SearchInRotatedSortedArray
{
	public class Solution
	{
		public int Search(int[] nums, int target)
		{
			if (nums.Length == 0)
			{
				return -1;
			}

			var start = 0;
			var end = nums.Length - 1;

			while (start <= end)
			{
				if (nums[start] == target)
				{
					return start;
				}

				if (nums[end] == target)
				{
					return end;
				}

				if (start >= end - 1)
				{
					return -1;
				}
				
				var index = (start + end) / 2;
				if (nums[index] == target)
				{
					return index;
				}

				if (nums[start] < nums[end])
				{
					if (target < nums[start] && target > nums[end])
					{
						return -1;
					}

					if (nums[index] <= target)
					{
						start = index;
					}
					else
					{
						end = index;
					}
				}
				else
				{
					if (nums[index] <= nums[end])
					{
						if (target >= nums[index] && target <= nums[end])
						{
							start = index;
						}
						else
						{
							end = index;
						}
					}
					else
					{
						if (target >= nums[start] && target <= nums[index])
						{
							end = index;
						}
						else
						{
							start = index;
						}
					}
				}
			}

			return -1;
		}
	}

	class Program
    {
        static void Main(string[] args)
        {
			var solution = new Solution();

			Console.WriteLine(solution.Search(new int[] { 4, 5, 6, 7, 0, 1, 2 }, 0));
			Console.WriteLine(solution.Search(new int[] { 4, 5, 6, 7, 0, 1, 2 }, 3));
			Console.WriteLine(solution.Search(new int[] { 3 }, 3));
			Console.WriteLine(solution.Search(new int[] { 3 }, 4));
			Console.WriteLine(solution.Search(new int[] { 3, 5 }, 3));
			Console.WriteLine(solution.Search(new int[] { 3, 5 }, 5));
			Console.WriteLine(solution.Search(new int[] { 1, 3, 5 }, 1));
			Console.WriteLine(solution.Search(new int[] { 4, 5, 6, 7, 0, 1, 2 }, 1));
			Console.WriteLine(solution.Search(new int[] { 4, 5, 6, 7, 0, 1, 2 }, 6));
			Console.WriteLine(solution.Search(new int[] { 4, 5, 6, 7, 8, 1, 2, 3 }, 8));

			Console.ReadKey();
        }
    }
}
