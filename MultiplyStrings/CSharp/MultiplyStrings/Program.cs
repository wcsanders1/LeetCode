using System;
using System.Text;

namespace MultiplyStrings
{
    public class Solution
    {
        public string Multiply(string num1, string num2)
        {
            if (string.IsNullOrWhiteSpace(num1) || string.IsNullOrWhiteSpace(num2) ||
                num1 == "0" || num2 == "0")
            {
                return "0";
            }

            string longerNum;
            string shorterNum;
            if (num1.Length == num2.Length)
            {
                longerNum = num1;
                shorterNum = num2;
            }
            else
            {
                longerNum = num1.Length > num2.Length ? num1 : num2;
                shorterNum = num1.Length < num2.Length ? num1 : num2;
            }

            var result = "0";

            for (var shortIndex = shorterNum.Length - 1; shortIndex >= 0; shortIndex--)
            {
                var zeros = shorterNum.Length - shortIndex - 1;
                var tempResult = new StringBuilder();

                for (int z = 0; z < zeros; z++)
                {
                    tempResult.Append("0");
                }

                var carry = 0;
                var shortDigit = int.Parse(shorterNum[shortIndex].ToString());
                for (var longIndex = longerNum.Length - 1; longIndex >= 0; longIndex--)
                {
                    var longDigit = int.Parse(longerNum[longIndex].ToString());
                    var times = ((shortDigit * longDigit) + carry).ToString();

                    if (times.Length == 2)
                    {
                        carry = int.Parse(times[0].ToString());
                        tempResult.Insert(0, times[1].ToString());
                    }
                    else
                    {
                        carry = 0;
                        tempResult.Insert(0, times[0].ToString());
                    }
                }

                if (carry > 0)
                {
                    tempResult.Insert(0, carry.ToString());
                }

                var tempResultStr = tempResult.ToString();

                string longerTempRes;
                string shorterTempRes;
                if (tempResultStr.Length == result.Length)
                {
                    longerTempRes = result;
                    shorterTempRes = tempResultStr;
                }
                else
                {
                    longerTempRes = tempResultStr.Length > result.Length ? tempResultStr : result;
                    shorterTempRes = tempResultStr.Length < result.Length ? tempResultStr : result;
                }

                carry = 0;
                var newRes = new StringBuilder();
                var shorterIndex = shorterTempRes.Length - 1;
                for (var i = longerTempRes.Length - 1; i >= 0 ; i--)
                {
                    var longerDigit = int.Parse(longerTempRes[i].ToString());
                    int shorterDigit;
                    if (shorterIndex >= 0)
                    {
                        shorterDigit = int.Parse(shorterTempRes[shorterIndex--].ToString());
                    }
                    else
                    {
                        shorterDigit = 0;
                    }

                    var newDigits = (longerDigit + shorterDigit + carry).ToString();
                    if (newDigits.Length == 2)
                    {
                        carry = int.Parse(newDigits[0].ToString());
                        newRes.Insert(0, newDigits[1]);
                    }
                    else
                    {
                        carry = 0;
                        newRes.Insert(0, newDigits[0]);
                    }
                }

                if (carry > 0)
                {
                    newRes.Insert(0, 1);
                }

                result = newRes.ToString();
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            //Console.WriteLine(solution.Multiply("6", "6")); //36
            //Console.WriteLine(solution.Multiply("35", "12")); //420
            //Console.WriteLine(solution.Multiply("123", "456")); //56088
            Console.WriteLine(solution.Multiply("123456789", "987654321")); // 121932631112635269
            Console.WriteLine(solution.Multiply("79362", "217")); // 17221554

            Console.ReadKey();
        }
    }
}
