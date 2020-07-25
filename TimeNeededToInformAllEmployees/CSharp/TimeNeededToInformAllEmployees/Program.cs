using System;
using System.Collections.Generic;

namespace TimeNeededToInformAllEmployees
{
    public class Employee
    {
        public int InformTime { get; set; }
        public List<Employee> Subordinates { get; set; } = new List<Employee>();
    }

    public class Solution
    {
        public int NumOfMinutes(int n, int headID, int[] manager, int[] informTime)
        {
            var employees = new Dictionary<int, Employee>
            {
                {
                    headID, new Employee
                    {
                        InformTime = informTime[headID]
                    }
                }
            };

            for (int i = 0; i < n; i++)
            {
                if (i == headID)
                {
                    continue;
                }

                if (!employees.TryGetValue(i, out var employee))
                {
                    employee = new Employee
                    {
                        InformTime = informTime[i]
                    };

                    employees.Add(i, employee);
                }

                var managerIndex = manager[i];

                if (!employees.TryGetValue(managerIndex, out var boss))
                {
                    boss = new Employee
                    {
                        InformTime = informTime[managerIndex]
                    };

                    employees.Add(managerIndex, boss);
                }

                boss.Subordinates.Add(employee);
            }

            return GetTotalTime(employees[headID]);
        }

        private int GetTotalTime(Employee boss, int totalTime = 0)
        {
            totalTime += boss.InformTime;

            var greatestTime = totalTime;
            foreach (var subordinate in boss.Subordinates)
            {
                var nextTime = GetTotalTime(subordinate, totalTime);

                if (nextTime > greatestTime)
                {
                    greatestTime = nextTime;
                }
            }

            return greatestTime;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.NumOfMinutes(1, 0, new int[] { -1 }, new int[] { 0 }));
            Console.WriteLine(solution.NumOfMinutes(6, 2, new int[] { 2, 2, -1, 2, 2, 2 }, new int[] { 0, 0, 1, 0, 0, 0 }));
            Console.WriteLine(solution.NumOfMinutes(7, 6, new int[] { 1, 2, 3, 4, 5, 6, -1 }, new int[] { 0, 6, 5, 4, 3, 2, 1 }));
            
            Console.WriteLine(solution.NumOfMinutes(15, 0, new int[] { -1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, }, 
                new int[] { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 }));

            Console.WriteLine(solution.NumOfMinutes(4, 2, new int[] { 3, 3, -1, 2 }, new int[] { 0, 0, 162, 914 }));

            Console.ReadKey();
        }
    }
}
