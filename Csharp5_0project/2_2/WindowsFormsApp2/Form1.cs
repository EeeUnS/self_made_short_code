using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void GroupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void BtnPoll_Click(object sender, EventArgs e)
        {
           if (this.chb01.Checked != false || this.chb02.Checked != false)
            {
                foreach (RadioButton c in this.gbHobby.Controls)
                {
                    if (c.Checked == true)
                    {
                        this.lblHobby.Text = c.Text;
                    }
                }
                this.lblSports.Text = "";
                foreach(CheckBox c in this.gbSports.Controls)
                {
                    if(c.Checked == true)
                    {
                        this.lblSports.Text += c.Text + " ";
                    }
                }
            }
        }
    }
}
