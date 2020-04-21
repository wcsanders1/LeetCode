using System;
using System.Text;

namespace CountAndSay
{
	public class Solution
	{
		public string CountAndSay(int n)
		{
			return CountAndSay(n, "1");
		}

		private string CountAndSay(int max, string say, int n = 1)
		{
			if (string.IsNullOrWhiteSpace(say))
			{
				return string.Empty;
			}

			if (n >= max)
			{
				return say;
			}

			var sb = new StringBuilder();
			var lastChar = say[0];
			var count = 1;

			for (var i = 1; i < say.Length; i++)
			{
				if (say[i] == lastChar)
				{
					count++;
				}
				else
				{
					sb.Append($"{count}{lastChar}");
					lastChar = say[i];
					count = 1;
				}
			}

			if (count > 0)
			{
				sb.Append($"{count}{lastChar}");
			}

			return CountAndSay(max, sb.ToString(), n + 1);
		}
	}

    class Program
    {
        static void Main(string[] args)
        {
			var solution = new Solution();

            Console.WriteLine(solution.CountAndSay(1));
			Console.WriteLine(solution.CountAndSay(2));
			Console.WriteLine(solution.CountAndSay(3));
			Console.WriteLine(solution.CountAndSay(4));
			Console.WriteLine(solution.CountAndSay(5));
			Console.WriteLine(solution.CountAndSay(6));

			Console.ReadKey();
        }
    }
}
