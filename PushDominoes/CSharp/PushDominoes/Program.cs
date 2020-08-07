using System;

namespace PushDominoes
{
    public class Solution
    {
        public string PushDominoes(string dominoes)
        {
            if (string.IsNullOrWhiteSpace(dominoes) || dominoes.Length < 2)
            {
                return dominoes;
            }

            var result = new char[dominoes.Length];

            for (int i = 0; i < dominoes.Length; i++)
            {
                var currentChar = dominoes[i];

                if (currentChar != '.')
                {
                    result[i] = currentChar;

                    continue;
                }

                var endIndex = GetEndIndex(dominoes, i);

                if (endIndex == dominoes.Length - 1)
                {
                    if (i == 0)
                    {
                        return dominoes;
                    }

                    for (int j = i; j < dominoes.Length; j++)
                    {
                        if (result[j - 1] == 'R')
                        {
                            result[j] = 'R';
                        }
                        else
                        {
                            result[j] = '.';
                        }
                    }

                    break;
                }

                var startIndex = i;
                i = endIndex;
                result[endIndex + 1] = dominoes[endIndex + 1];

                while (startIndex <= endIndex)
                {
                    if (startIndex == 0)
                    {
                        if (result[endIndex + 1] == 'L')
                        {
                            result[endIndex] = 'L';
                        }
                        else
                        {
                            result[endIndex] = '.';
                        }

                        endIndex--;

                        continue;
                    }
                    
                    if (startIndex == endIndex)
                    {
                        if (result[startIndex - 1] == 'R')
                        {
                            if (result[endIndex + 1] == 'L')
                            {
                                result[startIndex] = '.';
                            }
                            else
                            {
                                result[startIndex] = 'R';
                            }
                        }
                        else if (result[endIndex + 1] == 'L')
                        {
                            result[startIndex] = 'L';
                        }
                        else
                        {
                            result[startIndex] = '.';
                        }

                    }
                    else
                    {
                        if (result[startIndex - 1] == 'R')
                        {
                            result[startIndex] = 'R';
                        }
                        else if (result[endIndex + 1] == 'L')
                        {
                            while(startIndex <= endIndex)
                            {
                                result[endIndex--] = 'L';
                            }

                            break;
                        }
                        else
                        {
                            result[startIndex] = '.';
                        }

                        if (result[endIndex + 1] == 'L')
                        {
                            result[endIndex] = 'L';
                        }
                        else if (result[startIndex - 1] == 'R')
                        {
                            while (startIndex <= endIndex)
                            {
                                result[startIndex++] = 'R';
                            }

                            break;
                        }
                        else
                        {
                            result[endIndex] = '.';
                        }
                    }

                    startIndex++;
                    endIndex--;
                }
            }

            return new string(result);
        }

        private int GetEndIndex(string s, int start)
        {
            for (int i = start; i < s.Length; i++)
            {
                if (i == s.Length - 1 || s[i + 1] != '.')
                {
                    return i;
                }
            }

            return 0;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.PushDominoes(".L.R...LR..L.."));
            Console.WriteLine(solution.PushDominoes("RR.L"));
            Console.WriteLine(solution.PushDominoes("R."));
            Console.WriteLine(solution.PushDominoes(".."));
            Console.WriteLine(solution.PushDominoes("L.L...L.L.LL.L..L..."));

            Console.ReadKey();
        }
    }
}
