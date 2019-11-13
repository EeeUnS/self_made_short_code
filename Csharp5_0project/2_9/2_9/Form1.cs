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

    public partial class Form1 : Form
    {

        public static Point FormPt;
        public static Point FormPoint01;
        public static bool flag01;
        public static bool flag02;
        public static bool flag03;

        Form2 frm2 = new Form2();
        Form3 frm3 = new Form3();

        public Form1()
        {
            InitializeComponent();
        }

        private void PictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void Btnshow_Click(object sender, EventArgs e)
        {
            if(flag01 == false)
            {
                this.btnshow.Text = "슬라이드 닫힘";
                FormPoint01.X = this.Location.X;
                FormPoint01.Y = this.Location.Y + 30;
                this.TopMost = true;
                frm2.Visible = true;
                frm2.SlidingForm();
            }
            else
            {
                this.btnshow.Text = "슬라이드 열림";
                FormPoint01.X = this.Location.X + 300;
                FormPoint01.Y = this.Location.Y + 30;
                frm2.SlidingForm();
            }
        }

        private void Btnmag_LocationChanged(object sender, EventArgs e)
        {

        }

        private void Form1_LocationChanged(object sender, EventArgs e)
        {
            FormPt = this.Location;
            if(flag01 == true)
            {
                frm2.Left = this.Left + 300;
                frm2.Top = this.Top + 30;
            }
            else
            {
                frm2.Left = this.Left;
                frm2.Top = this.Top + 30;
            }
            if(flag02 == true && flag03 == true)
            {
                frm3.Location = new Point(this.Location.X, this.Location.Y + 300);
            }
        }

        private void Btnmag_Click(object sender, EventArgs e)
        {
            if(flag02 == false)
            {
                this.btnmag.Text = "폼 붙이기 닫기";
                frm3.Show();
                flag02 = true;
                flag03 = true;
                frm3.Location = new Point(this.Location.X, this.Location.Y + 310);
            }
            else
            {
                this.btnmag.Text = "폼 붙이기 열기";
                frm3.Hide();
                flag02 = false;
                flag03 = false;
            }
        }
    }
}
