using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void TsbtnFont_Click(object sender, EventArgs e)
        {
            if(this.fontdlg.ShowDialog() == DialogResult.OK)
            {
                this.rtbtext.SelectionFont = this.fontdlg.Font;
            }
        }

        private void TsbtnColor_Click(object sender, EventArgs e)
        {
            if (this.colordlg.ShowDialog() == DialogResult.OK)
            {
                this.rtbtext.SelectionColor = this.colordlg.Color;
            }
        }
    }
}
