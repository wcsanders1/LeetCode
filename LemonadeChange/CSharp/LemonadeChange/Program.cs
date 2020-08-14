using System;

namespace LemonadeChange
{
    public class Solution
    {
        public bool LemonadeChange(int[] bills)
        {
            if (bills == null || bills.Length == 0)
            {
                return true;
            }

            var fives = 0;
            var tens = 0;

            foreach (var bill in bills)
            {
                switch (bill)
                {
                    case 5:
                        fives++;
                        continue;
                    case 10:
                        tens++;
                        if (fives > 0)
                        {
                            fives--;
                            continue;
                        }
                        else
                        {
                            return false;
                        }
                    case 20:
                        if (tens > 0)
                        {
                            tens--;
                            if (fives > 0)
                            {
                                fives--;
                                continue;
                            }
                            else
                            {
                                return false;
                            }
                        }
                        else if (fives > 2)
                        {
                            fives -= 3;
                            continue;
                        }
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

            Console.WriteLine(solution.LemonadeChange(new int[] { 5, 5, 5, 10, 20}));
            Console.WriteLine(solution.LemonadeChange(new int[] { 5, 5, 10 }));
            Console.WriteLine(solution.LemonadeChange(new int[] { 10, 10 }));

            Console.ReadKey();
        }
    }
}
