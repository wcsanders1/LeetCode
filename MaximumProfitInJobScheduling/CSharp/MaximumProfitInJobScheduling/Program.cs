using System;
using System.Collections.Generic;
using System.Linq;

namespace MaximumProfitInJobScheduling
{
    public class JobSchedule
    {
        public int StartTime { get; set; }
        public int EndTime { get; set; }
        public int Profit { get; set; }
    }

    public class Solution
    {
        public int JobScheduling(int[] startTime, int[] endTime, int[] profit)
        {
            if (startTime.Length == 1)
            {
                return profit[0];
            }

            var jobSchedules = new List<JobSchedule>();
            for (int i = 0; i < startTime.Length; i++)
            {
                jobSchedules.Add(new JobSchedule
                {
                    StartTime = startTime[i],
                    EndTime = endTime[i],
                    Profit = profit[i]
                });
            };

            var orderedJobSchedules = jobSchedules.OrderBy(j => j.StartTime).ToList();
            var orderedStartTimes = orderedJobSchedules.Select(j => j.StartTime).ToArray();
            
            var profits = new int[startTime.Length];
            profits[^1] = orderedJobSchedules[^1].Profit;

            for (int i = startTime.Length - 2; i >= 0; i--)
            {
                var currentProfit = orderedJobSchedules[i].Profit;
                var currentEndTime = orderedJobSchedules[i].EndTime;

                var closestStartIndex = GetNextStartTimeIndex(currentEndTime, orderedStartTimes, i + 1, startTime.Length - 1);
                var nextClosest = 0;
                if (closestStartIndex > -1)
                {
                    nextClosest = profits[closestStartIndex] + currentProfit;
                }
                
                if (currentProfit < profits[i + 1])
                {
                    currentProfit = Math.Max(profits[i + 1], nextClosest);
                }

                profits[i] = Math.Max(currentProfit, nextClosest);
            }

            return profits[0];
        }

        private static int GetNextStartTimeIndex(int endTime, int[] startTimes, int begin, int end)
        {
            if (begin > end)
            {
                return -1;
            }

            var middle = (end + begin) / 2;

            if (endTime == startTimes[middle])
            {
                while (middle >= 0)
                {
                    if (endTime > startTimes[middle])
                    {
                        return middle + 1;
                    }

                    middle--;
                }

                return middle;
            }

            if (endTime > startTimes[middle])
            {
                return GetNextStartTimeIndex(endTime, startTimes, middle + 1, end);
            }

            var index = GetNextStartTimeIndex(endTime, startTimes, begin, middle - 1);

            return index > -1 ? index : middle;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.JobScheduling(new int[] { 1, 2, 3, 3 },
                new int[] { 3, 4, 5, 6 }, new int[] { 50, 10, 40, 70 }));

            Console.WriteLine(solution.JobScheduling(new int[] { 1, 2, 3, 4, 6 },
                new int[] { 3, 5, 10, 6, 9 }, new int[] { 20, 20, 100, 70, 60 }));

            Console.WriteLine(solution.JobScheduling(new int[] { 1, 1, 1 },
                new int[] { 2, 3, 4 }, new int[] { 5, 6, 4 }));

            Console.WriteLine(solution.JobScheduling(new int[] { 4, 2, 4, 8, 2 },
                new int[] { 5, 5, 5, 10, 8 }, new int[] { 1, 2, 8, 10, 4 }));

            Console.ReadKey();
        }
    }
}
