using System;
using System.Collections.Generic;
using System.Linq;

namespace SubstringWithConcatenationOfAllWords
{
    public class Solution
    {
        public IList<int> FindSubstring(string s, string[] words)
        {
            var wordsToCount = new Dictionary<string, int>();
            foreach (var word in words)
            {
                if (!wordsToCount.ContainsKey(word))
                {
                    wordsToCount.Add(word, 1);
                }
                else
                {
                    wordsToCount[word]++;
                }
            }

            var result = new List<int>();
            var indexes = new List<int>();
            var indexesToWord = new Dictionary<int, string>();

            var distinctWords = words.Distinct().ToList();

            foreach (var word in distinctWords)
            {
                var wordIndex = 0;
                for (int i = 0; i < s.Length; i++)
                {
                    if (wordIndex >= word.Length)
                    {
                        i -= wordIndex;
                        wordIndex = 0;
                        continue;
                    }

                    if (word[wordIndex] != s[i])
                    {
                        i -= wordIndex;
                        wordIndex = 0;
                        continue;
                    }

                    if (word[wordIndex] == s[i] && wordIndex == word.Length - 1)
                    {
                        var index = i + 1 - word.Length;
                        indexes.Add(index);
                        if (!indexesToWord.ContainsKey(index))
                        {
                            indexesToWord.Add(index, word);
                        }
                        i -= wordIndex;
                        wordIndex = 0;
                        continue;
                    }
                    wordIndex++;
                    
                }
            }

            var sortedIndexes = indexes.Distinct().OrderBy(i => i).ToList();

            if (words.Length == 1)
            {
                return sortedIndexes.Select(i => i).ToList();
            }

            for (int i = 0; i < sortedIndexes.Count; i++)
            {
                var index = sortedIndexes[i];
                var word = indexesToWord[index];

                var wordCount = 1;
                var wordsToCountCopy = new Dictionary<string, int>(wordsToCount);
                wordsToCountCopy[word]--;

                var lastWord = word;
                var lastIndex = index;
                var nextWordIndex = i + 1;

                while (nextWordIndex < sortedIndexes.Count)
                {
                    var nextIndex = sortedIndexes[nextWordIndex];
                    
                    if (nextIndex - lastIndex < lastWord.Length)
                    {
                        nextWordIndex++;
                        continue;
                    }

                    if (lastIndex + lastWord.Length < nextIndex)
                    {
                        break;
                    }

                    var nextWord = indexesToWord[nextIndex];

                    lastWord = nextWord;
                    lastIndex = nextIndex;
                    if (wordsToCountCopy[nextWord] > 0)
                    {
                        wordsToCountCopy[nextWord]--;
                        nextWordIndex++;
                        wordCount++;
                    }
                    else
                    {
                        break;
                    }

                    if (wordCount == words.Length)
                    {
                        result.Add(index);
                        break;
                    }
                }
            }

            return result.ToList();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.FindSubstring("barfoothefoobarman", new string[] { "foo", "bar" });
            var result2 = solution.FindSubstring("wordgoodgoodgoodbestword", new string[] { "word", "good", "best", "word" });
            var result3 = solution.FindSubstring("barfoofoobarthefoobarman", new string[] { "bar", "foo", "the" });
            var result4 = solution.FindSubstring("wordgoodgoodgoodbestword", new string[] { "word", "good", "best", "good" }); // [8]
            var result5 = solution.FindSubstring("a", new string[] { "a" }); // [0]
            var result6 = solution.FindSubstring("aaaaaaaa", new string[] { "aa", "aa", "aa" });
            var result7 = solution.FindSubstring("cccbcacaa", new string[] { "cc", "bc" });

            Console.ReadKey();
        }
    }
}
