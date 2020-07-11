using System;
using System.Collections.Generic;

namespace RestoreIPAddresses
{
    public class Solution
    {
        public IList<string> RestoreIpAddresses(string s)
        {
            var result = new List<string>();

            if (string.IsNullOrWhiteSpace(s) || s.Length < 4)
            {
                return result;
            }

            GetValidIPs(s, result);

            return result;
        }

        private void GetValidIPs(string s, List<string> validIPs, int decimalNumber = 1, int position = 1)
        {
            if (decimalNumber > 3 || position >= s.Length)
            {
                if (ValidateIP(s))
                {
                    validIPs.Add(s);
                }

                return;
            }

            for (int i = position; i < s.Length && i < position + 3; i++)
            {
                var possibleIP = PlaceDecimal(s, i);
                GetValidIPs(possibleIP, validIPs, decimalNumber + 1, i + 2);
            }
        }

        private string PlaceDecimal(string s, int position)
        {
            return $"{s.Substring(0, position)}.{s.Substring(position)}";
        }

        private bool ValidateIP(string s)
        {
            var parts = s.Split('.');
            if (parts.Length != 4)
            {
                return false;
            }

            foreach (var part in parts)
            {
                var isInt = int.TryParse(part, out var addr);
                if (!isInt || addr < 0 || addr > 255)
                {
                    return false;
                }

                if (part.Length > 1 && part[0] == '0')
                {
                    return false;
                }
            }

            return true;
        }
    }

    class Program
    {
        static void Main()
        {
            var solution = new Solution();

            var resultOne = solution.RestoreIpAddresses("25525511135");
            var resultTwo = solution.RestoreIpAddresses("010010");

            Console.ReadKey();
        }
    }
}
