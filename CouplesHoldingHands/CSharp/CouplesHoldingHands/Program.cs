using System;

namespace CouplesHoldingHands
{
    public class Solution
    {
        private class UnionFind
        {
            private int[] Parents;
            public int Count;

            public UnionFind(int n)
            {
                Parents = new int[n];
                for (int i = 0; i < n; i++)
                {
                    Parents[i] = i;
                }

                Count = n;
            }

            private int Find(int i)
            {
                if (Parents[i] == i)
                {
                    return i;
                }

                Parents[i] = Find(Parents[i]);

                return Parents[i];
            }

            public void Union(int i, int j)
            {
                var a = Find(i);
                var b = Find(j);

                if (a != b)
                {
                    Parents[a] = b;
                    Count--;
                }
            }
        }

        public int MinSwapsCouples(int[] row)
        {
            var N = row.Length / 2;
            var unionFind = new UnionFind(N);

            for (int i = 0; i < N; i++)
            {
                var a = row[i * 2];
                var b = row[i * 2 + 1];

                unionFind.Union(a / 2, b / 2);
            }

            return N - unionFind.Count;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.MinSwapsCouples(new int[] { 0, 2, 1, 3 }));
            Console.WriteLine(solution.MinSwapsCouples(new int[] { 3, 2, 0, 1 }));
            Console.WriteLine(solution.MinSwapsCouples(new int[] { 0, 2, 1, 4, 3, 5 }));
            Console.WriteLine(solution.MinSwapsCouples(new int[] { 0, 2, 4, 6, 7, 1, 3, 5 }));

            Console.ReadKey();
        }
    }
}
