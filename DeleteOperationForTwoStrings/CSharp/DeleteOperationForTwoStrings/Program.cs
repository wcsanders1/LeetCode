using System;

namespace DeleteOperationForTwoStrings
{
    public class Solution
    {
        public int MinDistance(string word1, string word2)
        {
            if (string.IsNullOrWhiteSpace(word1) && string.IsNullOrWhiteSpace(word2))
            {
                return 0;
            }

            if (string.IsNullOrWhiteSpace(word1))
            {
                return word2.Length;
            }

            if (string.IsNullOrWhiteSpace(word2))
            {
                return word1.Length;
            }

            var dp = new int[word1.Length + 1][];

            for (int row = 0; row < dp.Length; row++)
            {
                dp[row] = new int[word2.Length + 1];
            }

            for (int col = 1; col <= word1.Length; col++)
            {
                dp[col][0] = col;
            }

            for (int row = 1; row <= word2.Length; row++)
            {
                dp[0][row] = row;
            }

            for (int col = 1; col <= word1.Length; col++)
            {
                var colChar = word1[col - 1];

                for (int row = 1; row <= word2.Length; row++)
                {
                    var rowChar = word2[row - 1];

                    if (colChar == rowChar)
                    {
                        dp[col][row] = dp[col - 1][row - 1];
                    }
                    else
                    {
                        dp[col][row] = Math.Min(dp[col - 1][row], dp[col][row - 1]) + 1;
                    }
                }
            }

            return dp[word1.Length][word2.Length];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MinDistance("sea", "eat"));
            Console.WriteLine(solution.MinDistance("delete", "leet"));
            Console.WriteLine(solution.MinDistance("dinitrophenylhydrazine", "phenylhydrazine"));

            Console.ReadKey();
        }
    }
}
