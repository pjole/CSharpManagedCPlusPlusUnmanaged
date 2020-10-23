using CPlus;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CSharpManagedUnmanaged
{
    class Program
    {
        static void Main(string[] args)
        {
            W_newModuleHeader WnMH = new W_newModuleHeader();
            WnMH.id = 0;
            WnMH.index = 1;

            string _filePath = "BINARY.bin";
            Console.Write("WnMH2 before saving" +
                          "\nWnMH2.id : " + WnMH.id +
                          "\nWnMH2.index : " + WnMH.index + "\n\n");

            SaveToFile(_filePath, WnMH);
            WnMH.index = 0;
            Console.Write("WnMH2 before reading" +
                          "\nWnMH2.id : " + WnMH.id +
                          "\nWnMH2.index : " + WnMH.index + "\n\n");

            WnMH = ReadFromFile(_filePath, WnMH.StructSize);
            Console.Write("WnMH2 after reading" + 
                          "\nWnMH2.id : " + WnMH.id +
                          "\nWnMH2.index : " + WnMH.index);
            Console.ReadKey();

        }
        static public void SaveToFile(String _filePath, W_newModuleHeader WnMH)
        {
            byte[] buffer = null;
            try
            {
                FileStream stream = null;
                BinaryWriter writer = null;

                stream = new FileStream(_filePath, FileMode.Create);
                writer = new BinaryWriter(stream);
                buffer = new byte[WnMH.StructSize];
                Marshal.Copy(WnMH.StructPointer, buffer, 0, WnMH.StructSize);
                writer.Write(buffer);

                // close
                writer.Close();
                stream.Close();
            }
            catch (Exception ex)
            {
                Console.Write("Save File Error\n" + ex.ToString());
            }
        }

        static public W_newModuleHeader ReadFromFile(String _filePath, int size)
        {
            FileStream stream = null;
            BinaryReader reader = null;
            byte[] _fileData = new byte[4];

            try
            {
                // open
                stream = new FileStream(_filePath, FileMode.Open);
                reader = new BinaryReader(stream);

                // file header
                _fileData = reader.ReadBytes(size);
                GCHandle gch = GCHandle.Alloc(_fileData, GCHandleType.Pinned);
                IntPtr ptr = gch.AddrOfPinnedObject();
                
                // close
                reader.Close();
                stream.Close();
                return new W_newModuleHeader(ptr);
            }
            catch (Exception ex)
            {
                Console.Write("Read File Error\n" + ex.ToString());
                return null;
            }
        }


    }
}
