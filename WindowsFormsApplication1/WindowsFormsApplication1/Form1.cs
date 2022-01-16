using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.IO;
namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        string[] array = new string[10];

        public Form1()
        {
            InitializeComponent();
            array[0] = "293";
            array[1] = "0.000025";
            array[2] = "0.04";
            array[3] = "0.5";
            array[4] = "0.003";
            array[5] = "1";
            array[6] = "1.5";
            array[7] = "200";
            array[8] = "2";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        [DllImport("user32.dll")]
        static extern IntPtr SetParent(IntPtr hwc, IntPtr hwp);

        private void button1_Click(object sender, EventArgs e)
        {
            int i = 0;

            if (textBox1.Text != "")
                array[0] = (textBox1.Text);
            if (textBox3.Text != "")
                array[1] = (textBox3.Text);
            if (textBox9.Text != "")
                array[2] = (textBox9.Text);
            if (textBox8.Text != "")
                array[3] = (textBox8.Text);
            if (textBox6.Text != "")
                array[4] = (textBox6.Text);
            if (textBox2.Text != "")
                array[5] = (textBox2.Text);
            if (textBox7.Text != "")
                array[6] = (textBox7.Text);
            if (textBox4.Text != "")
                array[7] = (textBox4.Text);
            if (textBox5.Text != "")
                array[8] = (textBox5.Text);


            //File.WriteAllLines("C:\\Users\\Omar agha\\Desktop\\omar.txt",array);

            StreamWriter sw = new StreamWriter("omar.txt");
            sw.WriteLine(array[0]);
            sw.WriteLine(array[1]);
            sw.WriteLine(array[2]);
            sw.WriteLine(array[3]);
            sw.WriteLine(array[4]);
            sw.WriteLine(array[5]);
            sw.WriteLine(array[6]);
            sw.WriteLine(array[7]);
            sw.WriteLine(array[8]);
            sw.Close();
            /*
            Process p = Process.Start("C:\\Users\\AMRAN ALAA\\Desktop\\PROJECT\\loader and 3DS\\taleb\\model\\Debug\\model.exe");
            Thread.Sleep(500);



            //p.WaitForInputIdle();
            SetParent(p.MainWindowHandle, this.Handle);
            
            */
            ProcessStartInfo si = new ProcessStartInfo();

           // ifstream myfile;
            //myfile.open("c:\\client\\settings.cfg");

            si.FileName = @"model\\Debug\\model";
            si.Arguments = "model.h";

            Process.Start(si);


            textBox1.Clear();
            textBox2.Clear();
            textBox3.Clear();
            textBox4.Clear();
            textBox5.Clear();
            textBox6.Clear();
            textBox7.Clear();
            textBox8.Clear();
            textBox9.Clear();



        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
