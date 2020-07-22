using System;
using System.Collections.Generic;

namespace ProductOfTheLastKNumbers
{
    public class ProductOfNumbers
    {
        public List<int> Numbers { get; set; }

        public ProductOfNumbers()
        {
            Numbers = new List<int>();
        }

        public void Add(int num)
        {
            if (num == 0)
            {
                Numbers.Clear();
            }
            else
            {
                if (Numbers.Count == 0)
                {
                    Numbers.Add(num);
                }
                else
                {
                    Numbers.Add(Numbers[^1] * num);
                }
            }
        }

        public int GetProduct(int k)
        {
            if (k > Numbers.Count)
            {
                return 0;
            }

            if (k == Numbers.Count)
            {
                return Numbers[^1];
            }

            return Numbers[^1] / Numbers[Numbers.Count - 1 - k];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var product = new ProductOfNumbers();

            product.Add(3);

            Console.WriteLine(product.GetProduct(1));

            product.Add(0);

            Console.WriteLine(product.GetProduct(2));

            product.Add(2);
            product.Add(5);
            product.Add(4);

            Console.WriteLine(product.GetProduct(2));
            Console.WriteLine(product.GetProduct(3));
            Console.WriteLine(product.GetProduct(4));

            Console.ReadKey();
        }
    }
}
