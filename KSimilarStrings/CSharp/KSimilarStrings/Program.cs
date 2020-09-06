using System;
using System.Collections.Generic;

namespace KSimilarStrings
{
    public class Solution
    {
        public int KSimilarity(string A, string B)
        {
            if (A == B)
            {
                return 0;
            }

            var visited = new HashSet<string>();
            var queue = new Queue<string>();
            queue.Enqueue(A);
            visited.Add(A);
            var result = 0;

            while (queue.Count > 0)
            {
                result++;
                var count = queue.Count;
                for (int sz = count; sz > 0; sz--)
                {
                    var str = queue.Dequeue();
                    var i = 0;

                    while (str[i] == B[i])
                    {
                        i++;
                    }

                    for (int j = i + 1; j < str.Length; j++)
                    {
                        if (str[j] == B[j] || str[i] != B[j])
                        {
                            continue;
                        }

                        var newStr = Swap(str, j, i);
                        if (newStr == B)
                        {
                            return result;
                        }

                        if (visited.Contains(newStr))
                        {
                            continue;
                        }

                        visited.Add(newStr);
                        queue.Enqueue(newStr);
                    }
                }
            }

            return result;
        }

        private string Swap(string str, int a, int b)
        {
            var temp = str[a];
            var charArray = str.ToCharArray();
            charArray[a] = str[b];
            charArray[b] = temp;

            return new string(charArray);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.KSimilarity("ab", "ba"));
            Console.WriteLine(solution.KSimilarity("abc", "bca"));
            Console.WriteLine(solution.KSimilarity("abac", "baca"));
            Console.WriteLine(solution.KSimilarity("aabc", "abca"));
            Console.WriteLine(solution.KSimilarity("bccaba", "abacbc"));

            Console.ReadKey();
        }
    }
}
