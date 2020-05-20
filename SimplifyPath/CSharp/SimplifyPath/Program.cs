using System;
using System.Collections.Generic;
using System.Text;

namespace SimplifyPath
{
    public class Solution
    {
        public string SimplifyPath(string path)
        {
            if (string.IsNullOrWhiteSpace(path))
            {
                return "/";
            }

            var directories = new List<string>();
            var lastChar = path[0];

            for (var i = 1; i < path.Length; i++)
            {
                var currentChar = path[i];
                if (lastChar == '/')
                {
                    if (currentChar == '/')
                    {
                        continue;
                    }

                    if (currentChar == '.')
                    {
                        lastChar = '.';
                        continue;
                    }

                    var newDirectory = new StringBuilder();
                    while (i < path.Length && path[i] != '/' && path[i] != '.')
                    {
                        newDirectory.Append(path[i++]);
                    }

                    if (i < path.Length)
                    {
                        lastChar = path[i];
                    }

                    directories.Add(newDirectory.ToString());
                }
                else if (lastChar == '.')
                {
                    if (currentChar == '.')
                    {
                        if (i < path.Length - 1 && path[i + 1] != '/')
                        {
                            var newerDirectory = new StringBuilder("..");

                            while (i < path.Length - 1 && path[i + 1] != '/')
                            {
                                i++;
                                newerDirectory.Append(path[i]);
                            }

                            directories.Add(newerDirectory.ToString());
                            if (i < path.Length)
                            {
                                lastChar = path[i];
                            }
                            continue;
                        }

                        if (directories.Count > 0)
                        {
                            lastChar = '/';
                            i++;
                            directories.RemoveAt(directories.Count - 1);
                        }
                        continue;
                    }
                    else if (currentChar == '/')
                    {
                        lastChar = '/';
                        continue;
                    }

                    var newDirectory = new StringBuilder(".");
                    while (i < path.Length && path[i] != '/' && path[i] != '.')
                    {
                        newDirectory.Append(path[i++]);
                    }

                    if (i < path.Length)
                    {
                        lastChar = path[i];
                    }

                    directories.Add(newDirectory.ToString());
                }
                else
                {
                    lastChar = currentChar;
                }
            }

            if (directories.Count == 0)
            {
                return "/";
            }

            var result = new StringBuilder();
            foreach (var directory in directories)
            {
                result.Append($"/{directory}");
            }

            return result.ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();

            Console.WriteLine(solution.SimplifyPath("/home/"));
            Console.WriteLine(solution.SimplifyPath("/../"));
            Console.WriteLine(solution.SimplifyPath("/home/foo/"));
            Console.WriteLine(solution.SimplifyPath("/a/./b/../../c/"));
            Console.WriteLine(solution.SimplifyPath("/a/../../b/../c//.//"));
            Console.WriteLine(solution.SimplifyPath("/a//b////c/d//././/.."));
            Console.WriteLine(solution.SimplifyPath("/..."));
            Console.WriteLine(solution.SimplifyPath("/..hidden"));
            Console.WriteLine(solution.SimplifyPath("/.hidden"));
            Console.WriteLine(solution.SimplifyPath("/..aa/...hidden/"));

            Console.ReadKey();
        }
    }
}
