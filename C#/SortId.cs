using System;

//要求通过调用Array.Sort方法对Chair 对象数组
//按myID的unicode码值进行由大到小排序。

namespace SortId
{
    class Program
    {
        public class Chair:IComparable<Chair>
        {
            public double myPrice;
            public string myVendor, myID;
            public Chair() { }
            public Chair(double price, string vendor, string sku)
            {
                myPrice = price;
                myVendor = vendor;
                myID = sku;
            }
            public int CompareTo(Chair ch)
            {
                if (ch == null) return 1;
                int result = string.Compare(this.myID, ch.myID);
                return result;
            }
        }

        static void Main(string[] args)
        {
            Chair[] chairs = new Chair[4];
            chairs[0] = new Chair(150.0, "Lane", "99-88");
            chairs[1] = new Chair(250.0, "Lane", "99-00");
            chairs[2] = new Chair(100.0, "Lane", "98-88");
            chairs[3] = new Chair(120.0, "Harris", "93-9");
            Array.Sort(chairs);
            foreach (Chair c in chairs)
            {
                Console.WriteLine(c.myPrice + " " + c.myVendor + " " + c.myID);
            }
            Console.ReadLine();
        }
    }
}
