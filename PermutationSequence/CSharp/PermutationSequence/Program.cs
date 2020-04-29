using System;
using System.Collections.Generic;
using System.Text;

namespace PermutationSequence
{
    public class Solution
    {
        public string GetPermutation(int n, int k)
        {
            k--;

            var permutations = 1;
            var factors = new int[n - 1];
            var possibleDigits = new List<string>();
            for (int i = 1; i <= n; i++)
            {
                possibleDigits.Add(i.ToString());
                permutations *= i;
                
                if (i < n)
                {
                    factors[n - i - 1] = permutations;
                }
            }

            if (k > permutations)
            {
                return string.Empty;
            }

            var result = new StringBuilder();
            for (int i = 0; i < factors.Length; i++)
            {
                var index = k / factors[i];
                result.Append(possibleDigits[index].ToString());
                possibleDigits.RemoveAt(index);

                k %= factors[i];
            }

            result.Append(possibleDigits[0]);
            return result.ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.GetPermutation(4, 9));
            Console.WriteLine(solution.GetPermutation(8, 9876));

            Console.ReadKey();
        }
    }
}
