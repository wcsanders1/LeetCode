using System;
using System.Collections.Generic;
using System.Text;

namespace TextJustification
{
    public class Solution
    {
        private (int, int) GetSpaces(int maxWidth, int currentWidth, int wordCount)
        {
            if (currentWidth > maxWidth && wordCount == 1)
            {
                return (0, 0);
            }

            var spaces = (maxWidth - (currentWidth - wordCount));

            if (spaces <= 0)
            {
                return (1, 0);
            }

            if (wordCount > 1)
            {
                return (spaces / (wordCount - 1), spaces % (wordCount - 1));
            }

            return (spaces, 0);
        }

        public IList<string> FullJustify(string[] words, int maxWidth)
        {
            var result = new List<string>();

            var nextWords = new List<string>();
            var currentWidth = 0;
            for (var i = 0; i < words.Length; i++)
            {
                if (currentWidth + words[i].Length > maxWidth)
                {
                    var (spaces, extraSpaces) = GetSpaces(maxWidth, currentWidth, nextWords.Count);

                    var newString = new StringBuilder();
                    if (nextWords.Count == 1)
                    {
                        newString.Append(nextWords[0]);
                        newString.Append(' ', spaces);
                    }
                    else
                    {
                        for (var next = 0; next < nextWords.Count; next++)
                        {
                            newString.Append(nextWords[next]);
                            if (next < extraSpaces)
                            {
                                newString.Append(' ', 1 + spaces);
                            }
                            else if (next < nextWords.Count - 1)
                            {
                                newString.Append(' ', spaces);
                            }
                        }
                    }

                    result.Add(newString.ToString());

                    nextWords.Clear();
                    currentWidth = 0;
                }

                nextWords.Add(words[i]);
                currentWidth += words[i].Length + 1;
            }

            if (nextWords.Count > 0)
            {
                var newString = new StringBuilder();                
                for (var i = 0; i < nextWords.Count; i++)
                {
                    newString.Append(nextWords[i]);
                    if (i < nextWords.Count - 1)
                    {
                        newString.Append(' ');
                    }
                    else
                    {
                        newString.Append(' ', maxWidth - newString.Length);
                    }
                }
                result.Add(newString.ToString());
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            var result1 = solution.FullJustify(new string[] { "This", "is", "an", "example", "of", "text", "justification." }, 16);
            var result2 = solution.FullJustify(new string[] { "What", "must", "be", "acknowledgement", "shall", "be" }, 16);
            var result3 = solution.FullJustify(new string[] { "Science", "is", "what", "we", "understand", "well", "enough",
            "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"}, 20);
            var result4 = solution.FullJustify(new string[] { "Listen", "to", "many", "speak", "to", "a", "few" }, 6);

            Console.ReadKey();
        }
    }
}
