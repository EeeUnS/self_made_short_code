using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2_9
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void Pblmg_Click(object sender, EventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {
            SlidingForm();
        }
        public void SlidingForm()
        {
            Location = Form1.FormPoint01;
            Timer.Start(); 
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if(Form1.flag01 == false)
            {
                Location = new Point(Location.X + 10, Location.Y);
                if(Location.X ==Form1.FormPoint01.X + 300)
                {
                    Timer.Stop();
                    Form1.flag01 = true;
                }
            }
            else
            {
                Location = new Point(Location.X - 10, Location.Y);
                if(Location.X == Form1.FormPoint01.X - 300)
                {
                    Timer.Stop();
                    Form1.flag01 = false;
                }
            }
        }
    }
}
