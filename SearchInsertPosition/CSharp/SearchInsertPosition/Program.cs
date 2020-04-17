using System;

namespace SearchInsertPosition
{
	public class Solution
	{
		public int SearchInsert(int[] nums, int target)
		{
			if (nums.Length == 0)
			{
				return 0;
			}

			var start = 0;
			var end = nums.Length - 1;

			while (start <= end)
			{
				var middle = (start + end) / 2;

				var curNum = nums[middle];
				if (curNum == target)
				{
					return middle;
				}

				if (nums[start] > target)
				{
					return start;
				}

				if (nums[end] < target)
				{
					return end + 1;
				}

				if (start == middle)
				{
					if (target < nums[start])
					{
						return start;
					}

					if (nums[end] >= target)
					{
						return end;
					}

					return end + 1;
				}

				if (curNum < target)
				{
					start = middle;
				}
				else
				{
					end = middle;
				}
			}

			return 0;
		}
	}

	class Program
    {
        static void Main(string[] args)
        {
			var solution = new Solution();

			Console.WriteLine(solution.SearchInsert(new int[] { 1, 3, 5, 6 }, 5));
			Console.WriteLine(solution.SearchInsert(new int[] { 1, 3, 5, 6 }, 2));
			Console.WriteLine(solution.SearchInsert(new int[] { 1, 3, 5, 6 }, 7));
			Console.WriteLine(solution.SearchInsert(new int[] { 1, 3, 5, 6 }, 0));
			Console.WriteLine(solution.SearchInsert(new int[] { 1 }, 0));
			Console.WriteLine(solution.SearchInsert(new int[] { 1, 3, 5, 6, 8, 8, 9 }, 8));
			Console.WriteLine(solution.SearchInsert(new int[] { 1, 3, 5, 6, 8, 8, 9 }, 9));
			Console.WriteLine(solution.SearchInsert(new int[] { 1, 3, 5, 6, 8, 8, 9 }, 90));
			Console.WriteLine(solution.SearchInsert(new int[] { 1}, 2));

			Console.ReadKey();
        }
    }
}
