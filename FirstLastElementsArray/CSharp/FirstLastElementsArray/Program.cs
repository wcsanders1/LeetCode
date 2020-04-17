using System;

namespace FirstLastElementsArray
{
	public enum IndexPosition
	{
		Lowest,
		Highest
	}

	public class Solution
	{
		public int[] SearchRange(int[] nums, int target)
		{
			if (nums.Length == 0)
			{
				return new int[] { -1, -1 };
			}

			var lowestIndex = GetIndex(nums, 0, nums.Length - 1, target, IndexPosition.Lowest);

			if (lowestIndex == -1)
			{
				return new int[] { lowestIndex, -1 };
			}

			return new int[] 
			{ 
				lowestIndex, 
				GetIndex(nums, lowestIndex, nums.Length - 1, target, IndexPosition.Highest, lowestIndex) 
			};
		}

		private int GetIndex(int[] nums, int start, int end, int target, IndexPosition position, int currentIndex = -1)
		{
			if (start > end)
			{
				return currentIndex;
			}

			if (nums[start] > target || nums[end] < target)
			{
				return currentIndex;
			}

			var middle = (start + end) / 2;

			if (position == IndexPosition.Lowest)
			{
				if (nums[middle] == target)
				{
					return GetIndex(nums, start, middle - 1, target, position, middle);
				}

				if (nums[middle] < target)
				{
					return GetIndex(nums, middle + 1, end, target, position, currentIndex);
				}

				return GetIndex(nums, start, middle - 1, target, position, currentIndex);
			}

			if (nums[middle] == target)
			{
				return GetIndex(nums, middle + 1, end, target, position, middle);
			}

			if (nums[middle] < target)
			{
				return GetIndex(nums, middle + 1, end, target, position, currentIndex);
			}

			return GetIndex(nums, start, middle - 1, target, position, currentIndex);
		}
	}

	class Program
    {
        static void Main(string[] args)
        {
			var solution = new Solution();

			var result1 = solution.SearchRange(new int[] { 5, 7, 7, 8, 8, 10 }, 8);
			var result2 = solution.SearchRange(new int[] { 5, 7, 7, 8, 8, 10 }, 6);
			var result3 = solution.SearchRange(new int[] { 5, 5, 5, 5, 5, 5 }, 5);
			var result4 = solution.SearchRange(new int[] { 5, 5, 5, 5, 5, 6 }, 6);
			var result5 = solution.SearchRange(new int[] { 5, 7, 7, 7, 8, 8, 10 }, 8);

			Console.ReadKey();
        }
    }
}
