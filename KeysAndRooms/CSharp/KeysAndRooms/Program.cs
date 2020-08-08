using System;
using System.Collections.Generic;
using System.Linq;

namespace KeysAndRooms
{
    public class Solution
    {
        public bool CanVisitAllRooms(IList<IList<int>> rooms)
        {
            if (rooms == null || rooms.Count == 0)
            {
                return true;
            }

            var visited = new bool[rooms.Count];
            visited[0] = true;

            Visit(rooms, rooms[0], visited);

            return VisitedAll(visited);
        }

        private bool VisitedAll(bool[] visited)
        {
            return !visited.Any(v => !v);
        }

        private void Visit(IList<IList<int>> rooms, IList<int> room, bool[] visited)
        {
            foreach (var key in room)
            {
                if (visited[key])
                {
                    continue;
                }

                visited[key] = true;

                Visit(rooms, rooms[key], visited);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.CanVisitAllRooms(new List<IList<int>>
            {
                new List<int> {1},
                new List<int> {2},
                new List<int> {3},
                new List<int>()
            }));

            Console.WriteLine(solution.CanVisitAllRooms(new List<IList<int>>
            {
                new List<int> {1, 3},
                new List<int> {3, 0, 1},
                new List<int> {2},
                new List<int> {0}
            }));

            Console.ReadKey();
        }
    }
}
