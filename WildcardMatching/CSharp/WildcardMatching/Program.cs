using System;
using System.Linq;
using System.Text;

namespace WildcardMatching
{
    // I realize this code is bad. It works though. Someday I intend to make it better...
    public class Solution
    {
        public bool IsMatch(string s, string p)
        {
            var pIdx = 0;
            var sIdx = 0;

            if (string.IsNullOrWhiteSpace(s))
            {
                return !p.Any(c => c != '*');
            }

            if (string.IsNullOrWhiteSpace(p))
            {
                return s.Length == 0;
            }

            while (pIdx < p.Length && sIdx < s.Length)
            {
                if (pIdx == 0)
                {
                    var patternB = new StringBuilder();
                    if (p[pIdx] != '*')
                    {
                        while (pIdx < p.Length && p[pIdx] != '*')
                        {
                            patternB.Append(p[pIdx++]);
                        }

                        var pattern = patternB.ToString();
                        for (int i = 0; i < pattern.Length; i++)
                        {
                            if (sIdx >= s.Length)
                            {
                                return false;
                            }

                            if (s[sIdx] != pattern[i] && pattern[i] != '?')
                            {
                                return false;
                            }
                            sIdx++;
                        }
                    }
                    else
                    {
                        while (pIdx < p.Length && p[pIdx] == '*')
                        {
                            pIdx++;
                        }
                        
                        while (pIdx < p.Length && p[pIdx] != '*')
                        {
                            patternB.Append(p[pIdx++]);
                        }
                        var pattern = patternB.ToString();

                        if (string.IsNullOrWhiteSpace(pattern))
                        {
                            return true;
                        }

                        if (pIdx == p.Length)
                        {
                            var sEnd = s.Length - 1;
                            for (int patternEnd = pattern.Length - 1; patternEnd >= 0; patternEnd--)
                            {
                                if (sEnd < 0)
                                {
                                    return false;
                                }

                                if (pattern[patternEnd] != '?' && pattern[patternEnd] != s[sEnd])
                                {
                                    return false;
                                }
                                sEnd--;
                            }
                            return true;
                        }

                        var patternIdx = 0;
                        var tempSIdx = sIdx;
                        while (sIdx < s.Length)
                        {
                            if (s[sIdx++] == pattern[patternIdx] || pattern[patternIdx] == '?')
                            {
                                patternIdx++;
                                if (patternIdx >= pattern.Length)
                                {
                                    break;
                                }
                            }
                            else
                            {
                                sIdx = ++tempSIdx;
                                patternIdx = 0;
                            }

                            if (sIdx == s.Length)
                            {
                                return false;
                            }
                        }
                    }
                }
                else
                {
                    while (pIdx < p.Length && p[pIdx] == '*')
                    {
                        pIdx++;
                    }

                    if (pIdx == p.Length)
                    {
                        return true;
                    }

                    var patternB = new StringBuilder();
                    while (pIdx < p.Length && p[pIdx] != '*')
                    {
                        patternB.Append(p[pIdx++]);
                    }

                    var pattern = patternB.ToString();
                    var patternIdx = 0;
                    
                    if (pIdx == p.Length)
                    {
                        var sEnd = s.Length - 1;
                        for (int patternEnd = pattern.Length - 1; patternEnd >= 0; patternEnd--)
                        {
                            if (sEnd < 0 || sEnd < sIdx)
                            {
                                return false;
                            }

                            if (pattern[patternEnd] != '?' && pattern[patternEnd] != s[sEnd])
                            {
                                return false;
                            }
                            sEnd--;
                        }
                        return true;
                    }

                    var tempSIdx = sIdx;
                    while (sIdx < s.Length)
                    {
                        if (patternIdx == pattern.Length)
                        {
                            return false;
                        }

                        if (s[sIdx++] == pattern[patternIdx] || pattern[patternIdx] == '?')
                        {
                            patternIdx++;
                            if (patternIdx == pattern.Length)
                            {
                                break;
                            }
                        }
                        else
                        {
                            sIdx = ++tempSIdx;
                            patternIdx = 0;
                        }

                        if (sIdx == s.Length)
                        {
                            return false;
                        }
                    }
                }
            }

            if (pIdx < p.Length)
            {
                while (pIdx < p.Length && p[pIdx] == '*')
                {
                    pIdx++;
                }
            }

            if (pIdx < p.Length - 1)
            {
                return false;
            }

            if (p[^1] == '*')
            {
                return true;
            }

            return (pIdx == p.Length - 1 && sIdx == s.Length - 1) || (pIdx == p.Length && sIdx == s.Length);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.IsMatch("a", "aa")); //false
            Console.WriteLine(solution.IsMatch("aa", "a")); //false
            Console.WriteLine(solution.IsMatch("aa", "aa")); //true
            Console.WriteLine(solution.IsMatch("aa", "*")); //true
            Console.WriteLine(solution.IsMatch("cb", "?a")); // false
            Console.WriteLine(solution.IsMatch("adceb", "*a*b")); //true
            Console.WriteLine(solution.IsMatch("acdcb", "a*c?b")); // false
            Console.WriteLine(solution.IsMatch("ab", "?*")); // true
            Console.WriteLine(solution.IsMatch("", "*")); //true
            Console.WriteLine(solution.IsMatch("a", "")); // false
            Console.WriteLine(solution.IsMatch("a", "a*"));  //true
            Console.WriteLine(solution.IsMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a***********b"));  //false
            Console.WriteLine(solution.IsMatch(
                "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb",
                "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"));  //false
            Console.WriteLine(solution.IsMatch(
                "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbbaabbbbba",
                "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"));  //true
            Console.WriteLine(solution.IsMatch("abefcdgiescdfimde", "ab*cd?i*de")); //true
            Console.WriteLine(solution.IsMatch("zacabz", "*a?b*")); //false
            Console.WriteLine(solution.IsMatch("aaaa", "***a")); //true
            Console.WriteLine(solution.IsMatch("b", "*?*?*")); //false
            Console.WriteLine(solution.IsMatch("ho", "ho**")); //true
            Console.WriteLine(solution.IsMatch("abce", "abc*??")); //false

            Console.ReadKey();
        }
    }
}
