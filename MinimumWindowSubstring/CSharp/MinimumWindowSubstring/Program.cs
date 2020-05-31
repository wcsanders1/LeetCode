using System;
using System.Collections.Generic;

namespace MinimumWindowSubstring
{
    public class Solution
    {
        public string MinWindow(string s, string t)
        {
            if (string.IsNullOrWhiteSpace(s) || string.IsNullOrWhiteSpace(t))
            {
                return string.Empty;
            }

            var neededCharsByAmount = new Dictionary<char, int>();

            for (var i = 0; i < t.Length; i++)
            {
                if (!neededCharsByAmount.ContainsKey(t[i]))
                {
                    neededCharsByAmount.Add(t[i], 1);
                }
                else
                {
                    neededCharsByAmount[t[i]]++;
                }
            }

            var start = 0;
            var end = 0;
            var substringStart = 0;
            var substringEnd = s.Length + 1;

            var charsInSubstring = new Dictionary<char, int>
            {
                {s[0], 1 }
            };

            while (end < s.Length)
            {
                if (!SubstringHasNeededChars(neededCharsByAmount, charsInSubstring))
                {
                    if (end == s.Length - 1)
                    {
                        if (substringEnd - substringStart > s.Length)
                        {
                            return string.Empty;
                        }

                        return s.Substring(substringStart, substringEnd - substringStart + 1);
                    }

                    end++;
                    if (!charsInSubstring.ContainsKey(s[end]))
                    {
                        charsInSubstring.Add(s[end], 1);
                    }
                    else
                    {
                        charsInSubstring[s[end]]++;
                    }
                }
                else
                {
                    if (end - start < substringEnd - substringStart)
                    {
                        substringStart = start;
                        substringEnd = end;
                    }
                    charsInSubstring[s[start]]--;
                    start++;
                }
            }

            return string.Empty;
        }

        private bool SubstringHasNeededChars(Dictionary<char, int> neededChars, Dictionary<char, int> substring)
        {
            foreach (var kv in neededChars)
            {
                if (!substring.ContainsKey(kv.Key) || substring[kv.Key] < kv.Value)
                {
                    return false;
                }
            }

            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MinWindow("ADOBECODEBANC", "ABC"));
            Console.WriteLine(solution.MinWindow("AAAAAAAAAAA", "A"));
            Console.WriteLine(solution.MinWindow("AAAAAAAAAB", "AB"));
            Console.WriteLine(solution.MinWindow("AAAABAAAA", "AB"));
            Console.WriteLine(solution.MinWindow("AAAABBBC", "AC"));
            Console.WriteLine(solution.MinWindow("AAAABBBCAAAAAABB", "AC"));
            Console.WriteLine(solution.MinWindow("a", "b"));
            Console.WriteLine(solution.MinWindow("ab", "b"));
            Console.WriteLine(solution.MinWindow("a", "a"));
            Console.WriteLine(solution.MinWindow("ask_not_what_your_country_can_do_for_you_ask_what_you_can_do_for_your_country",
                "ask_country"));

            Console.WriteLine(solution.MinWindow("wegdtzwabazduwwdysdetrrctotpcepalxdewzezbfewbabbseinxbqqplitpxtcwwhuyntbtzxwzyaufihclztckdwccpeyonumbpnuonsnnsjscrvpsqsftohvfnvtbphcgxyumqjzltspmphefzjypsvugqqjhzlnylhkdqmolggxvneaopadivzqnpzurmhpxqcaiqruwztroxtcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanllpunlyohwfsssiazeixhebipfcdqdrcqiwftutcrbxjthlulvttcvdtaiwqlnsdvqkrngvghupcbcwnaqiclnvnvtfihylcqwvderjllannflchdklqxidvbjdijrnbpkftbqgpttcagghkqucpcgmfrqqajdbynitrbzgwukyaqhmibpzfxmkoeaqnftnvegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydhalrlgjeyfvxdstmfyhzjrxsfpcytabdcmwqvhuvmpssingpmnpvgmpletjzunewbamwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenkettylcoppdveeycpuybekulvpgqzmgjrbdrmficwlxarxegrejvrejmvrfuenexojqdqyfmjeoacvjvzsrqycfuvmozzuypfpsvnzjxeazgvibubunzyuvugmvhguyojrlysvxwxxesfioiebidxdzfpumyon",
                "ozgzyywxvtublcl"));

            Console.ReadKey();
        }
    }
}
