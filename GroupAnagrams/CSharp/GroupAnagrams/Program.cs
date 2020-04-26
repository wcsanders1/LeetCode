using System;
using System.Collections.Generic;
using System.Linq;

namespace GroupAnagrams
{
    public class Solution
    {
        public IList<IList<string>> GroupAnagrams(string[] strs)
        {
            var anagrams = new Dictionary<string, List<string>>();
            foreach (var word in strs)
            {
                var sorted = new string(word.OrderBy(c => c).ToArray());
                if (!anagrams.ContainsKey(sorted))
                {
                    anagrams.Add(sorted, new List<string> { word });
                }
                else
                {
                    anagrams[sorted].Add(word);
                }
            }

            var result = new List<IList<string>>();

            foreach (var (_, anagramList) in anagrams)
            {
                result.Add(anagramList);
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.GroupAnagrams(new string[] { "eat", "tea", "tan", "ate", "nat", "bat" });

            Console.ReadKey();
        }
    }
}
