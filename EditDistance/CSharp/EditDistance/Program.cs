using System;

namespace EditDistance
{
    // Vladimir Levenshtein's distance algorithm
    public class Solution
    {
        public int MinDistance(string word1, string word2)
        {
            var wordOneLength = word1.Length;
            var wordTwoLength = word2.Length;

            var grid = new int[wordOneLength + 1, wordTwoLength + 1];

            for (int i = 0; i <= wordOneLength; i++)
            {
                grid[i, 0] = i;
            }

            for (int i = 0; i <= wordTwoLength; i++)
            {
                grid[0, i] = i;
            }

            for (int i = 0; i < wordTwoLength; i++)
            {
                for (int j = 0; j < wordOneLength; j++)
                {
                    if (word2[i] == word1[j])
                    {
                        grid[j + 1, i + 1] = grid[j, i];
                    }
                    else
                    {
                        var replace = grid[j, i];
                        var delete = grid[j, i + 1];
                        var insert = grid[j + 1, i];
                        grid[j + 1, i + 1] = Math.Min(replace, Math.Min(delete, insert)) + 1;
                    }
                }
            }

            return grid[wordOneLength, wordTwoLength];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MinDistance("horse", "ros"));
            Console.WriteLine(solution.MinDistance("intention", "execution"));
            Console.WriteLine(solution.MinDistance("red", "der"));
            Console.WriteLine(solution.MinDistance("redder", "der"));
            Console.WriteLine(solution.MinDistance("red", "derrer"));
            Console.WriteLine(solution.MinDistance("", "derrer"));

            Console.ReadKey();
        }
    }
}
