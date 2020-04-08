using System;
using System.Text;

namespace IntegerToRoman
{
    public class Solution
    {
        public string IntToRoman(int num)
        {
            var result = new StringBuilder();

            while (num > 0)
            {
                switch (num)
                {
                    case var _ when num < 4:
                        while (num > 0)
                        {
                            result.Append("I");
                            num -= 1;
                        }
                        break;
                    case var _ when num == 4:
                        result.Append("IV");
                        num -= 4;
                        break;
                    case var _ when num == 5:
                        result.Append("V");
                        num -= 5;
                        break;
                    case var _ when num < 9:
                        result.Append("V");
                        num -= 5;
                        break;
                    case var _ when num == 9:
                        result.Append("IX");
                        num -= 9;
                        break;
                    case var _ when num < 40:
                        while (num > 9)
                        {
                            result.Append("X");
                            num -= 10;
                        }
                        break;
                    case var _ when num < 50:
                        result.Append("XL");
                        num -= 40;
                        break;
                    case var _ when num < 90:
                        result.Append("L");
                        num -= 50;
                        break;
                    case var _ when num < 100:
                        result.Append("XC");
                        num -= 90;
                        break;
                    case var _ when num < 400:
                        while (num >= 100)
                        {
                            result.Append("C");
                            num -= 100;
                        }
                        break;
                    case var _ when num < 500:
                        result.Append("CD");
                        num -= 400;
                        break;
                    case var _ when num < 900:
                        result.Append("D");
                        num -= 500;
                        break;
                    case var _ when num < 1000:
                        result.Append("CM");
                        num -= 900;
                        break;
                    default:
                        result.Append("M");
                        num -= 1000;
                        break;
                }
            }

            return result.ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.IntToRoman(3));
            Console.WriteLine(solution.IntToRoman(4));
            Console.WriteLine(solution.IntToRoman(9));
            Console.WriteLine(solution.IntToRoman(39));
            Console.WriteLine(solution.IntToRoman(49));
            Console.WriteLine(solution.IntToRoman(58));
            Console.WriteLine(solution.IntToRoman(91));
            Console.WriteLine(solution.IntToRoman(1994));
            Console.WriteLine(solution.IntToRoman(100));

            Console.ReadKey();
        }
    }
}
