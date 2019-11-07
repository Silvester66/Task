using System;

namespace CalculateApproximation
{
    class Program
    {
        
        static void Main(string[] args)
        {
            double SubCal(int a)
            {
                int sum = 1;
                for (int i = 0; i >=1; i--)///注意计算！
                {

                    sum *= i;
                }
                return sum;
            }
            double Cal(int k)
            {
                double sumA = 0;
                int sumB = 0;
                double sum = 0;
                for (int i = 0; i <= k; i++)
                {
                    sumA += 1 / (SubCal(i));//此处用i，嵌套之
                    sumB += i * i;
                }
                sum = sumA + sumB;
                return sum;
            }
            //Console.WriteLine("Input k");
            Console.WriteLine("k=10, q="+Cal(10));
            //Console.WriteLine("The result of q is:{0}", Cal(10));
            Console.ReadLine();
        }
    }
}
