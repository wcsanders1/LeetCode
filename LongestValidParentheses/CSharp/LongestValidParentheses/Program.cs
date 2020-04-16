using System;

namespace LongestValidParentheses
{
	public class Solution
	{
		private int GetClosingTagIndex(string s, int start)
		{
			var openingTags = 0;
			for (var i = start; i < s.Length; i++)
			{
				if (s[i] == '(')
				{
					openingTags++;
				}
				else
				{
					openingTags--;
				}

				if (openingTags == 0)
				{
					return i;
				}
			}

			return -1;
		}


		public int LongestValidParentheses(string s)
		{
			if (string.IsNullOrWhiteSpace(s))
			{
				return 0;
			}

			var longest = 0;
			var current = 0;

			for (var i = 0; i < s.Length; i++)
			{
				if (s[i] == '(')
				{
					var closingIndex = GetClosingTagIndex(s, i);
					if (closingIndex == -1)
					{
						if (current > longest)
						{
							longest = current;
						}
						current = 0;
						continue;
					}

					current += closingIndex - i + 1;
					if (current > longest)
					{
						longest = current;
					}

					i = closingIndex;
				}
				else
				{
					current = 0;
				}
			}

			return longest;
		}
	}

    class Program
    {
        static void Main(string[] args)
        {
			var solution = new Solution();

			Console.WriteLine(solution.LongestValidParentheses("(()")); //2
			Console.WriteLine(solution.LongestValidParentheses(")()())")); //4
			Console.WriteLine(solution.LongestValidParentheses("(())()(()()()()(")); //8
			Console.WriteLine(solution.LongestValidParentheses("(((()()")); //4
			Console.WriteLine(solution.LongestValidParentheses("))))))()))))")); //2
			Console.WriteLine(solution.LongestValidParentheses("))))))()((((((")); //2
			Console.WriteLine(solution.LongestValidParentheses(")()())()()(")); //4
			Console.WriteLine(solution.LongestValidParentheses("(()(((()")); //2

			Console.ReadKey();
        }
    }
}
