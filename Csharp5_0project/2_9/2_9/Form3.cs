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
    public partial class Form3 : Form
    {
        Point ptMouseCurrentPos;
        Point ptMouseNewPos;
        Point ptFormCurrentPos;
        Point ptFormNewPos;
        bool bFormMouseDown = false;
        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_MouseDown(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                bFormMouseDown = true;
                ptMouseCurrentPos = Control.MousePosition;
                ptFormCurrentPos = this.Location;
            }
        }

        private void Form3_MouseUp(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                bFormMouseDown = false;
                if(this.Location.X <= Form1.FormPt.X + 30
                    && this.Location.X >= Form1.FormPt.X - 30)
                {
                    if(this.Location.Y <= Form1.FormPt.Y + 340
                        && this.Location.Y>= Form1.FormPt.Y + 280)
                    {
                        this.Location = new Point(Form1.FormPt.X, Form1.FormPt.Y + 280);
                        Form1.flag03 = true;
                    }
                    else
                    {
                        Form1.flag03 = false;
                    }
                }
                else
                {
                    Form1.flag03 = false;
                }
            }
        }

        private void Form3_MouseMove(object sender, MouseEventArgs e)
        {
            if(bFormMouseDown == true)
            {
                ptMouseNewPos = Control.MousePosition;
                ptFormNewPos.X = ptMouseNewPos.X -
                ptMouseCurrentPos.X + ptFormCurrentPos.X;
                ptFormNewPos.Y = ptMouseNewPos.Y -
                    ptMouseCurrentPos.Y + ptFormCurrentPos.Y;

                this.Location = ptFormNewPos;
                ptFormCurrentPos = ptFormNewPos;
                ptMouseCurrentPos = ptMouseNewPos;

            }
        }
    }
}
