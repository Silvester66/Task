using System;

//某文件名为“*.txt”，其中*可能由若干个英文单词组成。
//将此文件名改为“*.dat”，
//并且单词之间用下划线连接，
//例如: hello world.txt，改为hello_world.dat

namespace ChangeFileName
{
    class Program
    {
        static void Main(string[] args)
        {

            string filename = @" hello world 1.2.txt";
            int indexDot = filename.LastIndexOf('.');
            string extendName = "dat";
            filename = filename.Substring(0, indexDot + 1);
            filename += extendName;
            string newname = filename.Trim();
            string[] splitStrings = newname.Split(' ');
            filename = string.Join("_", splitStrings);
            Console.WriteLine(filename);
            Console.ReadLine();
        }
    }
}
