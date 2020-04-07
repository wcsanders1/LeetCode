using System;
using System.Text;

namespace StringToInteger
{
    public class Solution
    {
        public int MyAtoi(string str)
        {
            if (string.IsNullOrWhiteSpace(str))
            {
                return 0;
            }

            var num = new StringBuilder();
            var isNegative = false;
            var signTaken = false;
            var digitTaken = false;

            for (var i = 0; i < str.Length; i++)
            {
                var curChar = str[i];
                if (char.IsDigit(curChar))
                {
                    digitTaken = true;
                    num.Append(curChar);
                    continue;
                }

                if (curChar != ' ' && curChar != '-' && curChar != '+' && num.Length == 0)
                {
                    return 0;
                }

                if (curChar == ' ' && digitTaken)
                {
                    break;
                }

                if ((curChar == '-' || curChar == '+') && digitTaken)
                {
                    break;
                }

                if (curChar == ' ' && signTaken)
                {
                    return 0;
                }

                if (curChar == '-' || curChar == '+')
                {
                    if (digitTaken)
                    {
                        break;
                    }

                    if (signTaken)
                    {
                        return 0;
                    }

                    if (curChar == '-')
                    {
                        isNegative = true;
                    }

                    signTaken = true;

                    continue;
                }

                if (num.Length > 0)
                {
                    break;
                }
            }

            if (!long.TryParse(num.ToString(), out var longResult))
            {
                if (!digitTaken)
                {
                    return 0;
                }

                if (isNegative)
                {
                    return int.MinValue;
                }

                return int.MaxValue;
            }

            if (!isNegative && longResult > int.MaxValue)
            {
                return int.MaxValue;
            }

            if (isNegative)
            {
                longResult *= -1;
            }

            if (longResult < int.MinValue)
            {
                return int.MinValue;
            }

            return (int)longResult;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            //Console.WriteLine(solution.MyAtoi("42"));
            //Console.WriteLine(solution.MyAtoi("       -42"));
            //Console.WriteLine(solution.MyAtoi("4193 with words"));
            //Console.WriteLine(solution.MyAtoi("words and 987"));
            //Console.WriteLine(solution.MyAtoi("-91283472332"));
            //Console.WriteLine(solution.MyAtoi("+-2"));
            //Console.WriteLine(solution.MyAtoi("20000000000000000000"));
            //Console.WriteLine(solution.MyAtoi("+"));
            //Console.WriteLine(solution.MyAtoi("-    234"));
            //Console.WriteLine(solution.MyAtoi("0-1"));
            //Console.WriteLine(solution.MyAtoi("    -88827   5655   U"));
            Console.WriteLine(solution.MyAtoi("-5-"));
            Console.WriteLine(solution.MyAtoi("-13+8"));
            Console.WriteLine(solution.MyAtoi("123-"));

            Console.ReadKey();
        }
    }
}
