using System;
using System.Collections.Generic;
using System.Linq;

namespace MostProfitAssigningWork
{
    public class DifficultyAndProfit
    {
        public int Difficulty { get; set; }
        public int Profit { get; set; }
    }

    public class Solution
    {
        public int MaxProfitAssignment(int[] difficulty, int[] profit, int[] worker)
        {
            if (difficulty == null || difficulty.Length == 0 ||
                profit == null || profit.Length == 0 ||
                worker == null || worker.Length == 0)
            {
                return 0;
            }

            var difficultyAndProfit = new List<DifficultyAndProfit>();
            for (int i = 0; i < difficulty.Length; i++)
            {
                difficultyAndProfit.Add(new DifficultyAndProfit
                {
                    Difficulty = difficulty[i],
                    Profit = profit[i]
                });
            }

            var orderedDifficultyAndProfit = difficultyAndProfit.OrderBy(d => d.Difficulty).ToList();

            var highest = 0;
            for (int i = 0; i < orderedDifficultyAndProfit.Count; i++)
            {
                if (highest > orderedDifficultyAndProfit[i].Profit)
                {
                    orderedDifficultyAndProfit[i].Profit = highest;
                }
                else
                {
                    highest = orderedDifficultyAndProfit[i].Profit;
                }
            }

            Array.Sort(worker);

            var result = 0;
            var currentProfitIndex = 0;
            var currentProfit = orderedDifficultyAndProfit[0].Profit;

            for (int i = 0; i < worker.Length; i++)
            {
                if (worker[i] < orderedDifficultyAndProfit[0].Difficulty)
                {
                    continue;
                }

                while(currentProfitIndex < orderedDifficultyAndProfit.Count && 
                    orderedDifficultyAndProfit[currentProfitIndex].Difficulty <= worker[i])
                {
                    currentProfit = orderedDifficultyAndProfit[currentProfitIndex].Profit;
                    currentProfitIndex++;
                }

                result += currentProfit;
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MaxProfitAssignment(new int[] { 2, 4, 6, 8, 10 }, new int[] { 10, 20, 30, 40, 50 }, new int[] { 4, 5, 6, 7 }));

            Console.WriteLine(solution.MaxProfitAssignment(new int[] { 49, 49, 76, 88, 100 },
                new int[] { 5, 8, 75, 89, 94 }, new int[] { 98, 72, 16, 27, 76 }));

            Console.WriteLine(solution.MaxProfitAssignment(new int[] { 68, 35, 52, 47, 86 },
                new int[] { 67, 17, 1, 81, 3 }, new int[] { 92, 10, 85, 84, 82 }));

            Console.WriteLine(solution.MaxProfitAssignment(new int[] { 5, 50, 92, 21, 24, 70, 17, 63, 30, 53 },
                new int[] { 68, 100, 3, 99, 56, 43, 26, 93, 55, 25 }, new int[] { 96, 3, 55, 30, 11, 58, 68, 36, 26, 1 }));

            Console.ReadKey();
        }
    }
}
